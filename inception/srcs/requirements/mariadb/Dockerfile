# Start from the Debian Buster image
FROM debian:buster

# Install required packages and MariaDB
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y mariadb-server && \
    mkdir -p /run/mysqld && chown mysql:mysql /run/mysqld && \
    rm -rf /var/lib/apt/lists/*

# Copy the custom configuration file
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Script to initialize the database and user
COPY ./conf/init-db.sh /docker-entrypoint-initdb.d/init_db.sh
RUN chmod +x /docker-entrypoint-initdb.d/init_db.sh

# Expose the MySQL port
EXPOSE 3306

# Start the MariaDB server
CMD ["/docker-entrypoint-initdb.d/init_db.sh"]
