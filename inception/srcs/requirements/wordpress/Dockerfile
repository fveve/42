# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arafa <arafa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 13:08:10 by arafa             #+#    #+#              #
#    Updated: 2024/10/15 14:25:35 by arafa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
FROM debian:buster

# Optional: Set the timezone and locale if needed
# ENV TZ=Europe/Paris
# RUN apt-get install -y tzdata && \
#     ln -fs /usr/share/zoneinfo/$TZ /etc/localtime && \
#     echo "$TZ" > /etc/timezone

# Install necessary packages
RUN apt update && \
    apt upgrade -y && \
    apt-get -y install wget && \
    apt-get install -y php7.3 \
                       php7.3-fpm \
                       php7.3-mysql \
                       mariadb-client && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Download and set up WordPress
RUN wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www && \
    tar -xzf /var/www/wordpress-6.0-fr_FR.tar.gz -C /var/www && \
    rm /var/www/wordpress-6.0-fr_FR.tar.gz && \
    chown -R www-data:www-data /var/www/wordpress && \
    chmod -R 755 /var/www/wordpress  # Ensure proper permissions

# Install WP-CLI
RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Create necessary directories for PHP-FPM
RUN mkdir -p /run/php && \
    mkdir -p /home/root/data/wordpress

# Copy the PHP-FPM pool configuration for WordPress
COPY conf/wordpress.conf /etc/php/7.3/fpm/pool.d/

# Expose PHP-FPM port
EXPOSE 9000

# Start PHP-FPM in the foreground
CMD ["php-fpm7.3", "-F", "-y", "/etc/php/7.3/fpm/php-fpm.conf"]
