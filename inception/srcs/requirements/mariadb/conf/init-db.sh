#!/bin/bash
set -e

# Start the MariaDB service
service mysql start

# Create the database if it does not exist
mysql -e "CREATE DATABASE IF NOT EXISTS \`${DB_NAME}\`;" 

# Create the user if it does not exist
mysql -e "CREATE USER IF NOT EXISTS \`${DB_USER}\`@'%' IDENTIFIED BY '${DB_PASSWORD}';" 

# Grant all privileges to the user for the database
mysql -e "GRANT ALL PRIVILEGES ON \`${DB_NAME}\`.* TO \`${DB_USER}\`@'%';" 

# Change the root user's password
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_PASSWORD}';" 

# Refresh privileges
mysql -e "FLUSH PRIVILEGES;"
