DROP DATABASE IF EXISTS im;
CREATE DATABASE im DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
CREATE USER 'hhou1'@'localhost' IDENTIFIED BY 'hhou1-1';
GRANT SELECT, INSERT, UPDATE, DELETE ON im.* TO 'hhou1'@'localhost';
FLUSH PRIVILEGES;

CREATE TABLE IF NOT EXISTS t_user (
    f_id INT(40) NOT NULL AUTO_INCREMENT COMMENT '用户的唯一id号',
    f_name VARCHAR(20) NOT NULL COMMENT '用户名，不可为空',
    f_pass VARCHAR(20) NOT NULL COMMENT '用户的密码，加密后的',
    f_nickname VARCHAR(20) NOT NULL COMMENT '用户昵称，不可为空',
    f_desc VARCHAR(20) DEFAULT NULL COMMENT '用户简介，一句话介绍，可以用作此用户的座右铭',
    f_updatetime TIMESTAMP NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '更新时间', 
    PRIMARY KEY (f_name),
    KEY(f_id, f_name)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE IF NOT EXISTS t_friend (
    f_id_1 INT(40),
    f_id_2 INT(40),
    primary key (f_id_1, f_id_2)
)ENGINE=InnoDB DEFAULT CHARSET=utf8;