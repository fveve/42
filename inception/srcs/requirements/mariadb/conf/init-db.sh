#!/bin/bash
set -e

# Start MariaDB in the background
echo "Starting MariaDB..."
service mysql start

# Allow some time for the server to start
sleep 10

# Check if MariaDB started successfully
if ! mysqladmin ping; then
    echo "MariaDB failed to start!"
    exit 1
fi

# Initialize the database
echo "Initializing database..."

# Create the database
mysql -e "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;" || { echo "Failed to create database"; exit 1; }

# Create the user and assign a password
mysql -e "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'localhost' IDENTIFIED BY '${SQL_PASSWORD}';" || { echo "Failed to create user"; exit 1; }

# Grant privileges to the user
mysql -e "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';" || { echo "Failed to grant privileges"; exit 1; }

# Modify the root user password
mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';" || { echo "Failed to modify root user"; exit 1; }

# Refresh privileges
mysql -e "FLUSH PRIVILEGES;" || { echo "Failed to flush privileges"; exit 1; }

# Indicate the script has completed
echo "Database initialization completed."

# Keep the container running by running the MariaDB server in the foreground
echo "Starting MariaDB in foreground..."
exec mysqld