# Start from the Debian Buster image
FROM debian:buster

# Environment variables for MariaDB
ENV MYSQL_ROOT_PASSWORD=root_password
ENV SQL_DATABASE=my_database
ENV SQL_USER=my_user
ENV SQL_PASSWORD=my_password

# Install required packages and MariaDB
RUN apt-get update -y && \
    apt-get upgrade -y && \
    apt-get install -y mariadb-server && \
    rm -rf /var/lib/apt/lists/*

# Copy the custom configuration file
COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# Script to initialize the database and user
COPY init_db.sh /docker-entrypoint-initdb.d/init_db.sh
RUN chmod +x /docker-entrypoint-initdb.d/init_db.sh

# Expose the MySQL port
EXPOSE 3306

# Start the MariaDB server
CMD ["mysqld"]