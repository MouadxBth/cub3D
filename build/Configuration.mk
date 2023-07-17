# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Configuration.mk                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 00:47:20 by mbouthai          #+#    #+#              #
#    Updated: 2023/06/25 23:11:55 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

define PROJECT_HEADER


   _____      _    ____      _
  / ____|    | |  |___ \    | |
 | |    _   _| |__  __) | __| |
 | |   | | | | '_ \|__ < / _` |
 | |___| |_| | |_) |__) | (_| |
  \_____\__,_|_.__/____/ \__,_|




endef
export PROJECT_HEADER

CC	:= gcc
CFLAGS	:= -Wall -Werror -Wextra -I$(HEADERS_DIR)/ -Ilib/libft/ -Ilib/gnl/ -I/usr/include -O3 #-fsanitize=address

LDFLAGS	:= -L./lib/libft -L/usr/lib -lft -lm -lmlx_Linux -lXext -lX11 -lz #-fsanitize=address

CLEAN_DIR	:= rm -fd

CLEAN_FILES	:= rm -f
