#-------------------------------------------------------------
#Assume-se uma distribuição Linux como sistema operacional padrão
#-------------------------------------------------------------

COMPILER = g++
#comando para remover pastas
RMDIR = rm -rf
#comando para remover arquivos
RM = rm -f

#Flags para geração automática de dependências
DEP_FLAGS = -MT $@ -MMD -MP -MF $(DEP_PATH)/$.d
LIBS = -lSDL2 -lSDL2_image -lSDL2_mixer -lSDL2_ttf -lm
FLAGS= -std=c++11 -pedantic -Wextra 
#-fmax-errors=5 -Wall

INC_PATH = include
SRC_PATH = src
BIN_PATH = bin
DEP_PATH = dep

#Uma lista de arquivos por extensão:
CPP_FILES= $(wildcard $(SRC_PATH)/*.cpp)
OBJ_FILES= $(addprefix $(BIN_PATH)/,$(notdir $(CPP_FILES:.cpp=.o)))
DEP_FILES = $(wildcard $(DEP_PATH)/*.d)

#Nome do executável
EXEC = MARCELO110130766

#-------------------------------------------------------------
#Caso o sistema seja windows
#-------------------------------------------------------------
ifeq ($(OS),Windows_NT)
#comando para remover um diretório recursivamente
RMDIR= rd /s /q
#comando para deletar um único arquivo
EM = del

#path da SDL
SDL_PATH = C:\DL2-2.0.5\x86_64-w64-mingw32

#Nome do executável
EXEC := $(EXEC).exe

else
UNAME_S := $(shell uname -s)

#-------------------------------------------------------------
#Caso o sistema seja windows
#-------------------------------------------------------------

ifeq ($(UNAME_S), Darwin)

LIBS = -lm -framework SDL2 -framework SDL2_image -framework SDL2_mixer -framework SDL2_ttf

endif
endif

all: $(EXEC)

$(EXEC): $(OBJ_FILES)
	$(COMPILER) -o $@ $^ $(LIBS)

$(BIN_PATH)/%.o: $(SRC_PATH)/%.cpp

ifeq ($(OS), Windows_NT)
	@if not exist $(DEP_PATH) @ mkdir $(DEP_PATH)
	@if not exist $(BIN_PATH) @ mkdir $(BIN_PATH)
else
	@mkdir -p $(DEP_PATH) $(BIN_PATH)
endif

	$(COMPILER) $(DEP_FLAGS) -c -o $@ $< -I$(INC_PATH) $(FLAGS)

-include $(DEP_FILES)

clean:
	$(RMDIR) $(BIN_PATH) $(DEP_PATH)
	$(RM) $(EXEC)

.PHONY: debug clean release again
#regra pra debug
print-% : ; @echo $* = $($*)

debug: FLAGS += -g -O0
debug: all

release: FLAGS += -O3 -mtune=native
release: all