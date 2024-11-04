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
# Utilisation de l'image Debian
FROM debian:buster

# Mise à jour et installation des paquets de base, incluant NGINX, Vim, Curl, et OpenSSL
RUN apt update && \
    apt upgrade -y && \
    apt install -y nginx vim curl openssl

# Création d'un dossier pour stocker le certificat SSL et génération du certificat auto-signé
RUN mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -out /etc/nginx/ssl/inception.crt -keyout /etc/nginx/ssl/inception.key -subj "/C=FR/ST=IDF/L=Perpignan/O=42/OU=42/CN=arafa.42.fr/UID=login"

# Création d'un dossier pour stocker les fichiers de configuration de NGINX
RUN mkdir -p /var/run/nginx

# Remplace le fichier de configuration de NGINX avec le fichier personnalisé
COPY conf/nginx.conf /etc/nginx/conf.d/default.conf

# Expose le port 443 pour les connexions HTTPS
EXPOSE 443

# Commande pour démarrer NGINX en premier plan
CMD ["nginx", "-g", "daemon off;"]
