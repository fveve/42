FROM	debian:buster

RUN		apt update &&\
		apt upgrade -y &&\
		apt-get	install mariadb-server -y &&\
		mkdir -p /run/mysqld && chown mysql:mysql /run/mysqld

COPY	conf/50-server.cnf	/etc/mysql/mariadb.conf.d/50-server.cnf

COPY	conf/init-db.sh /docker-entrypoint-initdb.d/
