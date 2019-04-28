#include "malloc.h"

static unsigned char has_initialized;
static unsigned int managed_memory_start;
static unsigned int managed_memory_end;
static unsigned int managed_memory_size;

/* heap buffer size �ѻ�������С*/
#define HEAPSIZE	500

/* heap start addrress ����ʼ��ַ*/
#define malloc_addr heap
/* heap size ���ڴ�*/
#define malloc_size HEAPSIZE

/* heap buffer �ѻ���*/
unsigned char heap[HEAPSIZE];

/**
  * @brief Initializes malloc's gloabl varialbe and head of heap memory
  * @param None
  * @retval None
  */
void malloc_init(void)
{
	mem_control_block * mcb = NULL;

	/* confirm heap's start address
	ȷ�϶ѵĿ�ʼ��ַ*/
	managed_memory_start = (unsigned int)malloc_addr;
	/* confirm heap's size
	ȷ���ѵĴ�С*/
	managed_memory_size = malloc_size;
	/*confirm heap's end address
	ȷ�϶ѵĽ�����ַ*/
	managed_memory_end = managed_memory_start + managed_memory_size;

	/* make mcb point to heap's start address
	ʹmcbָ��ѵĿ�ʼ��ַ*/
	mcb = (mem_control_block *)managed_memory_start;
	/*the first blcok is avaialbe
	��һ�������*/
	mcb->is_available = 1;
	/*there is no block before the first block
	�ڵ�һ����֮ǰû�п� */
	mcb->prior_blocksize = 0;
	/*the first block's block size is difference of between heap's size and control block
      ��һ����Ŀ��С�ǶѴ�С�Ϳ��ƿ�֮��Ĳ���*/
	mcb->current_blocksize = managed_memory_size - sizeof(mem_control_block);
	/* Initialize done */
	has_initialized = 1;
}

/**
  * @brief Dynamic distribute memory function
  * @param numbytes: what size you need
  * @retval a void pointer to the distribute first address
  */
void * malloc(unsigned int numbytes)
{
	unsigned int current_location,otherbck_location;
	/* This is the same as current_location, but cast to a memory_control_block
	����current_location��ͬ������ǿ��ת��Ϊmemory_control_block*/
	mem_control_block * current_location_mcb = NULL,* other_location_mcb = NULL;
	/* varialbe for saving return value and be set to 0 until we find something suitable
	���ڱ��淵��ֵ�ı�����������Ϊ0��ֱ���ҵ����ʵ�ֵ*/
	void * memory_location = NULL;
	/* current dividing block size
	�ָ���С*/
	unsigned int process_blocksize;

	/* Initialize if we haven't already done so
	�����δ��ʼ�������ʼ��*/
	if(! has_initialized) {
		malloc_init();
	}

	/* Begin searching at the start of managed memory
	���й��ڴ濪ʼʱ��ʼ����*/
	current_location = managed_memory_start;
	/* Keep going until we have searched all allocated space
    ������ȥ��ֱ���������������з���Ŀռ� */
	while(current_location != managed_memory_end){
		/* current_location and current_location_mcb point to the same address.  However,
		 * current_location_mcb is of the correct type, so we can use it as a struct. current_location
		 * is a void pointer so we can use it to calculate addresses.
		 current_location��current_location_mcbָ��ͬһ��ַ��
		 ���ǣ�current_location_mcb��������ȷ��������ǿ��Խ��������ṹ��
		 current_location��һ��voidָ�룬������ǿ��������������ַ��
		 */
		current_location_mcb = (mem_control_block *)current_location;
		/* judge whether current block is avaiable
		�жϵ�ǰ���Ƿ����*/
		if(current_location_mcb->is_available){
			/* judge whether current block size exactly fit for the need
			�жϵ�ǰ���С�Ƿ���ȫ������Ҫ*/
			if((current_location_mcb->current_blocksize == numbytes)){
				/* It is no longer available
				�����ٿ�����*/
				current_location_mcb->is_available = 0;
			    /* We own it
			    ����ӵ����*/
				memory_location = (void *)(current_location + sizeof(mem_control_block));
				/* Leave the loop
				�뿪ѭ��*/
				break;
			/* judge whether current block size is enough for dividing a new block
			�жϵ�ǰ���С�Ƿ����Էָ��¿�*/
			}else if(current_location_mcb->current_blocksize >= numbytes + sizeof(mem_control_block)){
				/* It is no longer available
				���Ѳ��ٿ���*/
				current_location_mcb->is_available = 0;
				/* because we will divide current blcok,before we changed current block size,we should
				 * save the integral size.
				 ��Ϊ���ǽ����ֵ�ǰ�飬�����Ǹı䵱ǰ���С֮ǰ������Ӧ�ñ���������С��*/
				process_blocksize = current_location_mcb->current_blocksize;
				/* Now blcok size could be changed
				���ڿ��Ը��Ŀ��С*/
				current_location_mcb->current_blocksize = numbytes;

				/* find the memory_control_block's head of remaining block and set parameter,block of no
				 * parameter can't be managed.
				 �ҵ�memory_control_block��ʣ���ͷ�����ò������޷������޲����顣*/
				other_location_mcb = (mem_control_block *)(current_location + numbytes \
												+ sizeof(mem_control_block));
				/* the remaining block is still avaiable
				ʣ��Ŀ���Ȼ����*/
				other_location_mcb->is_available = 1;
				/* of course,its prior block size is numbytes
				��Ȼ��������ǰ���С��numbytes*/
				other_location_mcb->prior_blocksize = numbytes;
				/* its size should get small
				���Ĵ�СӦ�ñ�С*/
				other_location_mcb->current_blocksize = process_blocksize - numbytes \
												- sizeof(mem_control_block);

				/* find the memory_control_block's head of block after current block and \
				 * set parameter--prior_blocksize.
				 �ڵ�ǰ���* set���� - prior_blocksize֮���ҵ�memory_control_block�Ŀ�ͷ��*/
				otherbck_location = current_location + process_blocksize \
											+ sizeof(mem_control_block);
				/* We need check wehter this block is on the edge of managed memeory!
				������Ҫ���������Ƿ�λ���й��ڴ�ı�Ե��*/
				if(otherbck_location != managed_memory_end){
					other_location_mcb = (mem_control_block *)(otherbck_location);
					/*  its prior block size has changed!
					����ǰ�Ŀ��С�Ѿ��ı�*/
					other_location_mcb->prior_blocksize = process_blocksize\
						- numbytes - sizeof(mem_control_block);
				}
				/*We own the occupied block ,not remaining block
				����ӵ�б�ռ�õĿ飬������ʣ���*/
				memory_location = (void *)(current_location + sizeof(mem_control_block));
				/* Leave the loop
				�뿪ѭ��*/
				break;
			}
		}
		/* current block is unavaiable or block size is too small and move to next block
		��ǰ�鲻���û���С̫С���ƶ�����һ����*/
		current_location += current_location_mcb->current_blocksize \
									+ sizeof(mem_control_block);
	}
	/* if we still don't have a valid location,we'll have to return NULL
	���������Ȼû����Ч��λ�ã����ǽ����ò�����NULL*/
	if(memory_location == NULL)	{
		return NULL;
	}
	/* return the pointer
	����ָ��*/
	return memory_location;
}

/**
  * @brief  free your unused block
  * @param  firstbyte: a pointer to first address of your unused block
  * @retval None
  */
//�ͷ�һ���ѷ�������ݿ飬ֻ�ǶԴ����ݿ��Լ���ǰ�����ݿ�Ŀ��ƿ�ͷ�����е�������û�ж�ʵ����Ч���������û��ɼ������򣩽��г�ʼ��������Ҳ����˵���������е����ݱ��ֲ��䡣
void free(void *firstbyte)
{
	unsigned int current_location,otherbck_location;
	mem_control_block * current_mcb = NULL,* next_mcb = NULL,* prior_mcb \
								= NULL,* other_mcb = NULL;
	/* Backup from the given pointer to find the current block
	�Ӹ���ָ�뱸���Բ��ҵ�ǰ��*/
	current_location = (unsigned int)firstbyte - sizeof(mem_control_block);
	current_mcb = (mem_control_block *)current_location;
	/* Mark the block as being avaiable
	������Ϊ����*/
	current_mcb->is_available = 1;

	/* find next block location
	�ҵ���һ����λ��*/
	otherbck_location = current_location + sizeof(mem_control_block) \
									+ current_mcb->current_blocksize;
	/* We need check wehter this block is on the edge of managed memeory!
	������Ҫ���������Ƿ�λ���й��ڴ�ı�Ե��*/
	if(otherbck_location != managed_memory_end){
		/* point to next block
		ָ����һ����*/
		next_mcb = (mem_control_block *)otherbck_location;
		/* We need check whether its next block is avaiable
		������Ҫ���������һ�����Ƿ����*/
		if(next_mcb->is_available){
			/* Because its next block is also avaiable,we should merge blocks
			��Ϊ������һ����Ҳ�ǿ��õģ�����Ӧ�úϲ���*/
			current_mcb->current_blocksize = current_mcb->current_blocksize \
				+ sizeof(mem_control_block) + next_mcb->current_blocksize;

			/* We have merge two blocks,so we need change prior_blocksize of
			 * block after the two blocks,just find next block location.
			 ���Ǻϲ��������飬����������Ҫ��������֮����Ŀ��previous_blocksize��ֻ���ҵ���һ����λ�á�*/
			otherbck_location = current_location + sizeof(mem_control_block) \
									+ current_mcb->current_blocksize;
			/* We need check wehter this block is on the edge of managed memeory!
			������Ҫ���������Ƿ�λ���й��ڴ�ı�Ե��*/
			if(otherbck_location != managed_memory_end){
				other_mcb = (mem_control_block *)otherbck_location;
				/*  its prior block size has changed!
				��֮ǰ�Ŀ��С�Ѿ��ı��ˣ�*/
				other_mcb->prior_blocksize = current_mcb->current_blocksize;
			}
		}
	}

	/* We need check wehter this block is on the edge of managed memeory!
	������Ҫ���������Ƿ�λ���й��ڴ�ı�Ե��*/
	if(current_location != managed_memory_start){
		/* point to prior block
		ָ��ǰһ����*/
		prior_mcb = (mem_control_block *)(current_location - sizeof(mem_control_block)\
											- current_mcb->prior_blocksize);
		/* We need check whether its prior block is avaiable
		������Ҫ���������ǰ���Ƿ����*/
		if(prior_mcb->is_available){
			/* Because its prior block is also avaiable,we should merge blocks
			��Ϊ������ǰ��Ҳ�ǿ��õģ���������Ӧ�úϲ���*/
			prior_mcb->current_blocksize = prior_mcb->current_blocksize \
				+ sizeof(mem_control_block) + current_mcb->current_blocksize;

			/* We have merge two blocks,so we need change prior_blocksize of
			 * block after the two blocks,just find next block location.
			 ���Ǻϲ��������飬����������Ҫ��������֮����Ŀ��previous_blocksize��ֻ���ҵ���һ����λ�á�*/
			otherbck_location = current_location + sizeof(mem_control_block) \
									+ current_mcb->current_blocksize;
			/* We need check wehter this block is on the edge of managed memeory!
			������Ҫ���������Ƿ�λ���й��ڴ�ı�Ե��*/
			if(otherbck_location != managed_memory_end){
				other_mcb = (mem_control_block *)otherbck_location;
				/*  its prior block size has changed!
				��֮ǰ�Ŀ��С�Ѿ��ı��ˣ�*/
				other_mcb->prior_blocksize = prior_mcb->current_blocksize;
			}
		}
	}
}
