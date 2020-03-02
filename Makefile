NAME = uls

LMXD = libmx

INCD = inc

LMXI:= $(LMXD)/$(INCD)

SRCD = src

OBJD = obj

LMXA:= $(LMXD)/libmx.a

INC = uls.h

INCS = $(addprefix $(INCD)/, $(INC))

SRC = main.c mx_basic_flags.c mx_check_control_char.c mx_check_flags.c \
mx_color.c mx_columns.c mx_control_char_name.c mx_count_flags_in_str.c \
mx_creat_list.c mx_dir_argument.c mx_dir_arr.c mx_error_print.c \
mx_file_argument.c mx_flag_link.c mx_flags_for_sort.c mx_flags_into_arr.c \
mx_full_path.c mx_get_acl.c mx_get_blocks.c mx_get_data.c mx_get_dev.c \
mx_get_file_col.c mx_get_flag_f.c mx_get_flag_l.c mx_get_flags_for_file.c \
mx_get_gid.c mx_get_ino.c mx_get_is.c mx_get_law.c mx_get_link.c \
mx_get_minmaj.c mx_get_rdev.c mx_get_result.c mx_get_size_bytes.c \
mx_get_time.c mx_get_uid.c mx_head_size.c mx_islink.c mx_isspecial.c \
mx_itoa_sp.c mx_last_char.c mx_many_argument.c mx_num_file.c \
mx_one_argument.c mx_other_flags.c mx_print_error.c mx_print_file.c \
mx_print_flag_f.c mx_print_l.c mx_print_m.c mx_print_spase.c \
mx_print_to_file.c mx_print_x.c mx_printerr_char.c mx_printerr.c \
mx_printstr_update.c mx_read_dir.c mx_read_flags.c mx_read_link.c \
mx_size_all.c mx_sort_all.c mx_sort_dir_alp.c mx_sort_dir_arr.c mx_sort_dir.c \
mx_sort_file.c mx_sort_my_list.c mx_sort_revers.c mx_sort_size.c \
mx_sort_time.c \

SRCS = $(addprefix $(SRCD)/, $(SRC))

OBJS = $(addprefix $(OBJD)/, $(SRC:%.c=%.o))

CFLG = -std=c11 $(addprefix -W, all extra error pedantic) -g

all: install

install: $(LMXA) $(NAME)

$(LMXA):
	@make -sC $(LMXD)

$(NAME): $(OBJS)
	@clang $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%)"

$(OBJD):
	@mkdir -p $@

$(OBJS): | $(OBJD)

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t \033[31;1mdeleted\033[0m\n"

reinstall: uninstall install

