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

FROM	debian:buster

RUN		apt update &&\
		apt upgrade -y &&\
		apt-get -y install wget &&\
		apt-get install -y php7.3\
		php-fpm\
		php-mysql\
		mariadb-client

RUN		wget https://fr.wordpress.org/wordpress-6.0-fr_FR.tar.gz -P /var/www &&\
		cd /var/www && tar -xzf wordpress-6.0-fr_FR.tar.gz && rm wordpress-6.0-fr_FR.tar.gz &&\
		chown -R www-data:www-data /var/www/wordpress

RUN		wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar\
		chmod +x wp-cli.phar\
		mv wp-cli.phar /usr/local/bin/wp

COPY	conf/wordpress.conf /etc/php/php.conf