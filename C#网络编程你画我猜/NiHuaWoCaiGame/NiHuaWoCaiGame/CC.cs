﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NiHuaWoCaiGame
{
    public class CC
    {
        //连接的用户，每个用户都对应一个GameService线程
        public static List<User> Users { get; set; }
        //游戏大厅开出的最大房间数（每房间一桌）
        public const int maxRooms = 15;
        //游戏大厅开出的房间数（游戏桌数）
        public static Room[] Rooms { get; set; }


        public static User GetUser(string userName)
        {
            User user = null;
            foreach (var v in Users)
            {
                if (v.UserName == userName)
                {
                    user = v;
                    break;
                }
            }
            return user;
        }

        public static User GetUserById(int id)
        {
            User user = null;
            foreach (var v in Users)
            {
                if (v.Id == id)
                {
                    user = v;
                    break;
                }
            }
            return user;
        }
    }
}
