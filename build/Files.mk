# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Files.mk                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbouthai <mbouthai@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 23:45:12 by mbouthai          #+#    #+#              #
#    Updated: 2023/06/24 09:02:06 by mbouthai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Headers/Includes

HEADERS_DIR	:= inc

#HEADERS	=
#HEADERS	:= $(addprefix $(HEADERS_DIR)/,$(HEADERS))

# Sources

SRCS_DIR	:= src

COLOR_DIR	:= color
COLOR_SRCS	= color_utils.c color.c
COLOR_SRCS	:= $(addprefix $(COLOR_DIR)/,$(COLOR_SRCS))

WINDOW_DIR	:= window
WINDOW_SRCS	= image_utils.c image.c window.c
WINDOW_SRCS	:= $(addprefix $(WINDOW_DIR)/,$(WINDOW_SRCS))

PARSER_DIR	:= parser
PARSER_SRCS	= file_parse_utils.c map_textures_parse.c file_parse.c map_parse.c
PARSER_SRCS	:= $(addprefix $(PARSER_DIR)/,$(PARSER_SRCS))

RENDERER_DIR	:= renderer
RENDERER_SRCS	= renderer_utils.c point_renderer.c raycaster_renderer.c renderer.c
RENDERER_SRCS	:= $(addprefix $(RENDERER_DIR)/,$(RENDERER_SRCS))

MAP_DIR	:= map
MAP_SRCS	= map_utils.c map.c
MAP_SRCS	:= $(addprefix $(MAP_DIR)/,$(MAP_SRCS))

INFO_DIR	:= info
INFO_SRCS	= info.c info_rendering.c
INFO_SRCS	:= $(addprefix $(INFO_DIR)/,$(INFO_SRCS))

PLAYER_DIR	:= player
PLAYER_SRCS	= player_movement.c player.c
PLAYER_SRCS	:= $(addprefix $(PLAYER_DIR)/,$(PLAYER_SRCS))

VECTOR_DIR	:= vector
VECTOR_SRCS	= vector.c
VECTOR_SRCS	:= $(addprefix $(VECTOR_DIR)/,$(VECTOR_SRCS))

RAYCASTER_DIR	:= raycaster
RAYCASTER_SRCS	= raycaster_utils.c raycaster.c
RAYCASTER_SRCS	:= $(addprefix $(RAYCASTER_DIR)/,$(RAYCASTER_SRCS))

INIT_DIR	:= init
INIT_SRCS	= initialize_first.c initialize_second.c
INIT_SRCS	:= $(addprefix $(INIT_DIR)/,$(INIT_SRCS))

TEXTURE_DIR	:= texture
TEXTURE_SRCS	= texture.c
TEXTURE_SRCS	:= $(addprefix $(TEXTURE_DIR)/,$(TEXTURE_SRCS))

SOURCES	= main.c \
	$(COLOR_SRCS) \
	$(WINDOW_SRCS) \
	$(PARSER_SRCS) \
	$(RENDERER_SRCS) \
	$(MAP_SRCS) \
	$(INFO_SRCS) \
	$(PLAYER_SRCS) \
	$(VECTOR_SRCS) \
	$(RAYCASTER_SRCS) \
	$(INIT_SRCS) \
	$(TEXTURE_SRCS)

SOURCES	:= $(addprefix $(SRCS_DIR)/,$(SOURCES))

# Objects/Output files

OBJS_DIR	= obj
#OBJECTS	:= $(patsubst %,%.o,$(addprefix $(OBJS_DIR)/,$(notdir $(SOURCES))))
OBJECTS	:= $(patsubst $(SRCS_DIR)/%,$(OBJS_DIR)/%.o,$(SOURCES))

# Dependencies

DEPS_DIR	= dep
DEPENDENCIES	:= $(patsubst %,%.d,$(addprefix $(DEPS_DIR)/,$(notdir $(SOURCES))))

DIRS	= $(COLOR_DIR) \
	$(WINDOW_DIR) \
	$(PARSER_DIR) \
	$(RENDERER_DIR) \
	$(MAP_DIR) \
	$(INFO_DIR) \
	$(PLAYER_DIR) \
	$(VECTOR_DIR) \
	$(RAYCASTER_DIR) \
	$(INIT_DIR) \
	$(TEXTURE_DIR)
DIRS	:= $(addprefix $(OBJS_DIR)/,$(DIRS))
