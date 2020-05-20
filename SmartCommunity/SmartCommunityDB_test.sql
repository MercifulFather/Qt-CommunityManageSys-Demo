--
-- 由SQLiteStudio v3.2.1 产生的文件 周五 1月 3 12:24:53 2020
--
-- 文本编码：UTF-8
--
PRAGMA foreign_keys = off;
BEGIN TRANSACTION;

-- 表：attendance
DROP TABLE IF EXISTS attendance;

CREATE TABLE attendance (
    id           INTEGER PRIMARY KEY AUTOINCREMENT
                         NOT NULL,
    username     TEXT,
    signin_time  TIME,
    signout_time TIME,
    date         DATE,
    CONSTRAINT fkey0 FOREIGN KEY (
        username
    )
    REFERENCES user (username) ON UPDATE CASCADE
);

INSERT INTO attendance (id, username, signin_time, signout_time, date) VALUES (1, NULL, '16:13:23', NULL, '2020-01-02');
INSERT INTO attendance (id, username, signin_time, signout_time, date) VALUES (2, 'root', '16:35:28', '16:49:02', '2020-01-02');
INSERT INTO attendance (id, username, signin_time, signout_time, date) VALUES (3, 'root', '16:37:10', NULL, '2020-01-02');
INSERT INTO attendance (id, username, signin_time, signout_time, date) VALUES (4, 'root', '16:40:05', NULL, '2020-01-02');
INSERT INTO attendance (id, username, signin_time, signout_time, date) VALUES (5, 'root', '16:42:11', NULL, '2020-01-02');
INSERT INTO attendance (id, username, signin_time, signout_time, date) VALUES (6, 'root', '16:49:01', NULL, '2020-01-02');
INSERT INTO attendance (id, username, signin_time, signout_time, date) VALUES (7, '3', '11:55:03', '11:55:04', '2020-01-03');
INSERT INTO attendance (id, username, signin_time, signout_time, date) VALUES (8, '1', '12:17:05', '12:17:06', '2020-01-03');

-- 表：leave
DROP TABLE IF EXISTS leave;

CREATE TABLE leave (
    id         INTEGER PRIMARY KEY AUTOINCREMENT
                       NOT NULL,
    username   TEXT    NOT NULL,
    reason     TEXT,
    start_time DATE,
    end_time   DATE,
    state      TEXT,
    CONSTRAINT user_username FOREIGN KEY (
        username
    )
    REFERENCES user (username) ON UPDATE CASCADE
);

INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (1, 'root', '14513451', 151345, 14513451, '已通过');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (2, 'root', '14361356', 3461346, '周三 1月 1 2020', '已销假');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (3, '111', '2452345', 362346234, 324623462364, '待销假');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (4, 'root', '14132512512351235123512351', '周一 1月 3 2000', '周二 1月 11 2000', '待审批');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (5, 'root', '14132512512351235123512351', '周一 1月 3 2000', '周二 1月 11 2000', '待销假');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (6, 'root', '', '周三 1月 1 2020', '周五 1月 3 2020', '待销假');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (7, 'root', '', '周三 1月 1 2020', '周三 1月 1 2020', '待销假');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (8, 'root', '5555555555555555555', '周三 1月 1 2020', '周三 1月 1 2020', '待审批');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (9, 'root', '5555555555555555555', '周三 1月 1 2020', '周三 1月 1 2020', '待销假');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (10, 'root', '99999999999999999999999', '周三 1月 1 2020', '周三 1月 1 2020', '待销假');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (11, 'root', '777777777777777777777', '周三 1月 1 2020', '周三 1月 1 2020', '待销假');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (12, 'root', '88888888888888888888888888', '周三 1月 1 2020', '周三 1月 1 2020', '已销假');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (13, 'root', '12312313131', '周日 1月 12 2020', '周六 1月 18 2020', '待审批');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (14, 'root', '', '周日 1月 12 2020', '周六 1月 18 2020', '待审批');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (15, 'root', '', '周一 1月 13 2020', '周二 1月 14 2020', '待审批');
INSERT INTO leave (id, username, reason, start_time, end_time, state) VALUES (16, '3', '11111', '周三 1月 1 2020', '周三 1月 1 2020', '已销假');

-- 表：parking
DROP TABLE IF EXISTS parking;

CREATE TABLE parking (
    id          INTEGER PRIMARY KEY AUTOINCREMENT
                        NOT NULL,
    position    TEXT,
    type        TEXT,
    chargeable  TEXT,
    size        TEXT,
    state       TEXT,
    license     TEXT,
    username    TEXT    REFERENCES user (username) ON DELETE SET NULL
                                                   ON UPDATE CASCADE,
    expair_time DATE,
    pay_state   TEXT
);

INSERT INTO parking (id, position, type, chargeable, size, state, license, username, expair_time, pay_state) VALUES (1, '11111', '楼层', '否', '大', NULL, NULL, NULL, NULL, NULL);
INSERT INTO parking (id, position, type, chargeable, size, state, license, username, expair_time, pay_state) VALUES (2, '3332', '地上', '否', '大', NULL, NULL, NULL, NULL, NULL);
INSERT INTO parking (id, position, type, chargeable, size, state, license, username, expair_time, pay_state) VALUES (3, '88888', '地上', '否', '大', '使用中', NULL, 'root', '周一 1月 6 2020', '未支付');
INSERT INTO parking (id, position, type, chargeable, size, state, license, username, expair_time, pay_state) VALUES (4, '3333', '地上', '否', '小', '空闲', NULL, NULL, NULL, NULL);

-- 表：pay
DROP TABLE IF EXISTS pay;

CREATE TABLE pay (
    id       INTEGER PRIMARY KEY AUTOINCREMENT
                     NOT NULL,
    pay_date DATE,
    type     TEXT    REFERENCES price (type) ON DELETE CASCADE
                                             ON UPDATE CASCADE,
    username TEXT    REFERENCES user (username) ON DELETE CASCADE
                                                ON UPDATE CASCADE,
    quantity INTEGER
);

INSERT INTO pay (id, pay_date, type, username, quantity) VALUES (1, '2020-01-03', NULL, '1111', 333);
INSERT INTO pay (id, pay_date, type, username, quantity) VALUES (2, '2020-01-03', '物业费', '2', 333);

-- 表：price
DROP TABLE IF EXISTS price;

CREATE TABLE price (
    id     INTEGER PRIMARY KEY AUTOINCREMENT
                   NOT NULL,
    type   TEXT    UNIQUE,
    unit   TEXT,
    amount REAL
);

INSERT INTO price (id, type, unit, amount) VALUES (1, '维修费', '元', 3.0);
INSERT INTO price (id, type, unit, amount) VALUES (2, '车位费', '美元', 5.09);
INSERT INTO price (id, type, unit, amount) VALUES (3, '物业费', '元', 1.0);

-- 表：queue
DROP TABLE IF EXISTS queue;

CREATE TABLE queue (
    id         INTEGER PRIMARY KEY AUTOINCREMENT
                       NOT NULL,
    username   TEXT    REFERENCES user (username) ON DELETE CASCADE
                                                  ON UPDATE CASCADE,
    license    TEXT,
    size       TEXT,
    chargeable TEXT
);


-- 表：repair
DROP TABLE IF EXISTS repair;

CREATE TABLE repair (
    id          INTEGER PRIMARY KEY AUTOINCREMENT
                        NOT NULL,
    username    TEXT    REFERENCES user (username) ON DELETE CASCADE
                                                   ON UPDATE CASCADE,
    information TEXT,
    state       TEXT,
    result      TEXT,
    content     TEXT
);

INSERT INTO repair (id, username, information, state, result, content) VALUES (1, '3', '12415351', NULL, NULL, NULL);
INSERT INTO repair (id, username, information, state, result, content) VALUES (2, '2', '55555', '正在维修', '成功', '555555');

-- 表：settings
DROP TABLE IF EXISTS settings;

CREATE TABLE settings (
    id         INTEGER PRIMARY KEY AUTOINCREMENT
                       NOT NULL,
    author     TEXT,
    alter_time DATE
);


-- 表：user
DROP TABLE IF EXISTS user;

CREATE TABLE user (
    id       INTEGER PRIMARY KEY AUTOINCREMENT
                     NOT NULL,
    username TEXT,
    password TEXT,
    role     INTEGER,
    phone    INTEGER,
    address  TEXT,
    CONSTRAINT unique_username UNIQUE (
        username
    )
);

INSERT INTO user (id, username, password, role, phone, address) VALUES (1, '111', '11111', 2, NULL, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (2, '1112', '1111', 2, NULL, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (3, 'root', 'root111', 0, NULL, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (7, '123', '321', 2, NULL, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (9, '54325', '3452345', 0, NULL, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (10, '111111', '11111111', 2, NULL, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (11, '434343', '343434', NULL, NULL, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (12, 'qerrwqer', 'qerqwerqwer', 1, 124234541, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (13, '33232', NULL, 2, 1123321312, '');
INSERT INTO user (id, username, password, role, phone, address) VALUES (14, '525252', NULL, 2, 252525, '222255555');
INSERT INTO user (id, username, password, role, phone, address) VALUES (15, '222', NULL, 2, 0, '000000');
INSERT INTO user (id, username, password, role, phone, address) VALUES (16, '3', '3', 3, NULL, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (17, '0', '0', 0, NULL, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (18, '1', '1', 1, NULL, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (19, '2', '2', 2, NULL, NULL);
INSERT INTO user (id, username, password, role, phone, address) VALUES (21, '9', '9', 1, 9999, 'uuuuuuu');
INSERT INTO user (id, username, password, role, phone, address) VALUES (22, '7777777', NULL, 2, 7777, '777777777');

COMMIT TRANSACTION;
PRAGMA foreign_keys = on;
