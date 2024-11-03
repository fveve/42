# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arafa <arafa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/14 13:08:10 by arafa             #+#    #+#              #
#    Updated: 2024/10/14 14:29:59 by arafa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM	debian:buster

RUN		apt update &&\
		apt upgrade -y &&\
		mkdir -p /etc/nginx/ssl &&\
		apt install nginx curl vim openssl -y &&\
		openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/CN=arafa.42.fr" &&\
		mkdir -p /var/run/nginx
#La commande req crée et traite principalement des demandes de certificats au format PKCS#10.
#Elle peut en outre créer des certificats auto-signés.

RUN chmod 755 /var/www/html

RUN chown -R www-data:www-data /var/www/html

COPY	conf/nginx.conf /etc/nginx/sites-available/default

CMD [ "nginx", "-g", "daemon off;" ]