#ifndef __MALLOC_H
#define __MALLOC_H

//#define malloc_addr 0x20000000
//#define malloc_size 0x100000
#define NULL 0

//ÿ����һ���ڴ�ռ䣬���۴�С��char��short��long������������Ϊ"Block"��ͨ��Block��ͷ�����ƿ齫��������һ��������ͨ������������Ա�������������ÿһ���顣
//��is_avilable����ڴ���Ƿ񱻷��䣬�Ƿ���á�prior_blocksize������ǰһ����Ĵ�С��current_blocksize�����˵�ǰ���ʵ����Ч���ݿռ��С��
//����current_blocksize�����ǿ��Դ�ǰ����������������������prior_blocksize�����ǿ��ԴӺ���ǰ��������������
//������ƿ�ͷ��ʹ����Ϊ����������һ��˫���������Ա��ڹ�����
typedef struct{
unsigned char is_available;			/* whether blcok is avaiable */
unsigned int prior_blocksize;       /* size of prior block */
unsigned int current_blocksize;     /* block size */
}mem_control_block;

//#define malloc_init()	Rewrite_malloc_init()
//#define malloc(x)		Rewrite_malloc(x)
//#define free(x)			Rewrite_free(x)



void malloc_init(void);
/*
��ʼ����������Ҫ��ȷ����������ʼλ�á���С�ͽ�����ַ��Ҳ����ȷ�������ı߽硣����������ڴ������ڶ����ڣ����ó����߽磬������޸����������ݡ�

�������⣬����Ҫ�Զ������г�ʼ����������һ���ڴ�飨��ʼ��ͷ�����ƽṹ�壩��
    ��Ȼ���������һ�������Ŀ飬Ҳ��һ���ܷ�������ڴ�ռ�Ŀ顣֮���Խ��г�ʼ����ԭ����û��ͷ�����ƽṹ��Ŀ��޷����й�����
*/

void * malloc(unsigned int numbytes);
/*
����malloc����ʱ���������ӱ���ǰ���Ѱ��һ��û�б�ռ�õģ����Ҵ����������û���������Ҫ���ڴ�顣��Ѱ�ҹ����У������������

������һ��������������ö��Ҵ�С�պú��ʣ���ôֱ�ӽ��˿鷵�ؾ�����˷��䡣

�����ڶ���������������ö��ҳ���������Ҫ���ڴ�鲢�һ�������һ���¿�Ŀ���ͷ�������ʱ��ͽ��˿�һ��Ϊ����
    ��������û����ǿ��ڴ��is_available��0�����ٿ��ã���Ȼ�󽫴˿����Ч�������׵�ַ��Ϊ����ֵ���ء�
    ���¿�Ŀ���ͷ��Ҫ���и�ֵ��ֻ�к���ͷ���Ŀ���ܳƵ���һ���飩��û�п���ͷ���Ŀ鲻�ܽ��й�����

  ����������������������ڴ��Ŀռ�С����Ҫ�Ŀռ䣬������Ȼ�����˵��ǲ����ڳ�һ������ͷ�������յĴ������������Ŀ飬�ƶ�����������һ�������һ�ֵıȽϡ�
  */

void free(void *firstbyte);
/*
free���������ڴ��Ļ��գ������õ��ڴ����ô˺����ͷſռ��ʱ�򣬽�is_available��1���������·��䣩��
������Ҫ���ľ��������ڴ���Ƭ�����ڿ��ܶ��malloc�����������˺ܶ���ڴ���Ƭ�����ͷ�һ�����ʱ�򣬲���Ҫ��Ǵ˿�Ϊ�����á���
���⣬����Ҫ���Ž��˿�ǰ��Ŀ���кϲ�����������Ϊ�����������Ŀռ�����׼����
*/


#endif