CC=	clang
RM=	rm -f
ZIP=	tar
UNZIP=	tar
MKDIR=	mkdir -p
BKP_DIR=	fakeProj_backUp/
SOURCES_DIR=	./
CFLAGS+=	-Iinclude/
CFLAGS+=	-ftest-coverage -O2
LDFLAGS=	
ZIPFLAGS=	-cvvf
UNZIPFLAGS=	-xvf
SRC=	$(SOURCES_DIR)main.c $(SOURCES_DIR)calc.c 
OBJ=	$(SRC:.c=.o)
NAME=	fakeProj
all:	$(NAME)
$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
clean:	
	$(RM) $(OBJ)
fclean:	clean
	$(RM) $(NAME)
re:	fclean all
archive:
ifeq ($(wildcard $(BKP_DIR)/.),)
	$(MKDIR) $(BKP_DIR)
endif
ifneq ($(SRC),)
	$(ZIP) $(ZIPFLAGS) $(BKP_DIR)$(NAME).tar $(SRC)
	@echo "$(NAME).tar file generated."
ifeq ($(wildcard .proj_version),)
	@echo 1 > .proj_version
else
	@expr `cat .proj_version` + 1 > .proj_version
endif
endif
revert:
ifneq ($(wildcard $(BKP_DIR)$(NAME).tar),)
	$(UNZIP) $(UNZIPFLAGS) $(BKP_DIR)$(NAME).tar
endif
num:
ifneq ($(wildcard .proj_version),)
	@echo Version `cat .proj_version`
else
	@echo 0
endif
delete:
	$(RM) $(BKP_DIR)$(NAME).tar
.PHONY:	all clean fclean re archive revert num delete
