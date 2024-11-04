#!/bin/bash
set -e

# Start the MariaDB service
service mysql start

# Create the database if it does not exist
mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;" 

# Create the user if it does not exist
mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';" 

# Grant all privileges to the user for the database
mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'localhost';" 

# Change the root user's password
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';" 

# Refresh privileges
mysql -e "FLUSH PRIVILEGES;"
