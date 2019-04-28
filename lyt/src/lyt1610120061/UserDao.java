package lyt1610120061;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class UserDao extends DBOper{
    //��ȡ�û��б�
    public List<User> getUser(){
        List<User>userList = new ArrayList<User>();
        User user = new User();
        String sql = "SELECT * FROM tb_user";
        try{
            ResultSet rs = this.executeQuery(sql,null);
            while(rs.next()){
                user.setUsername(rs.getString("username"));
                user.setUserpass(rs.getString("userpass"));
                user.setImage(rs.getString("image"));
                user.setSex(rs.getString("sex"));
                user.setPhone(rs.getString("phone"));
                user.setEmail(rs.getString("email"));
                userList.add(user);
            }

        }catch(SQLException e){
            e.printStackTrace();
        }finally{
            this.closeAll();
        }
        return userList;
    }
    //�����û�����ȡ�û�
    public User getUserByName(String name){
        User user = null;
        String sql = "SELECT * FROM tb_user WHERE��username = ?";
        try{            
            ResultSet rs = this.executeQuery(sql, new String[]{name});
            if(rs.next()){
                user = new User();
                user.setUsername(rs.getString("username"));
                user.setUserpass(rs.getString("userpass"));
                user.setSex(rs.getString("sex"));
                user.setPhone(rs.getString("phone"));
                user.setEmail(rs.getString("email"));
            }
        }catch(SQLException e){
            e.printStackTrace();
        }finally{
            this.closeAll();
        }
        return user;
    }
    //�޸��û���Ϣ
    public boolean editUser(User user){
        boolean r = false;
        String sql = "UPDATE tb_user SET userpass = ?,sex = ?,phone = ?,email = ? iamge=? WHERE username = ?";
        try{
            int num = this.executeUpdate(sql, new String[]{user.getUserpass(),user.getSex(),user.getPhone(),user.getEmail(),user.getUsername()});
            if(num > 0){
                r = true;
            }
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            this.closeAll();
        }
        return r;

    }
    //����û�
    public boolean addUser(User user){
        boolean r = false;
        String sql = "INSERT INTO tb_user(username,userpass,sex,phone,email,image)VALUES(?,?,?,?,?,?) ";
        try{
            int num = this.executeUpdate(sql,new String[]{user.getUsername(),user.getUserpass(),user.getSex(),user.getPhone(),user.getEmail(),user.getImage()});
            if(num > 0){
                r = true;
            }
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            this.closeAll();
        }
        return r;
    }
    //ɾ��ָ���û�
    public boolean delUser(String name){
        boolean r = false;
        String sql = "DELETE FROM tb_user WHERE username = ?";
        try{
            int num = this.executeUpdate(sql,new String[]{name});
            if(num > 0){
                r = true;
            }
        }catch(Exception e){
            e.printStackTrace();
        }finally{
            this.closeAll();
        }
        return r;
    }
}