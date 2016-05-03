##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=V_rep_Tutorial
ConfigurationName      :=Debug
WorkspacePath          := "/home/ervin/CProjects/codelite_workspace"
ProjectPath            := "/home/ervin/CProjects/codelite_workspace/V_rep_Tutorial"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ervin
Date                   :=28/02/16
CodeLitePath           :="/home/ervin/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=$(PreprocessorSwitch)NON_MATLAB_PARSING $(PreprocessorSwitch)MAX_EXT_API_CONNECTIONS=255 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="V_rep_Tutorial.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)pthread 
ArLibs                 :=  "pthread" 
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/extApi.c$(ObjectSuffix) $(IntermediateDirectory)/extApiPlatform.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/V_rep_Tutorial/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/extApi.c$(ObjectSuffix): extApi.c $(IntermediateDirectory)/extApi.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/V_rep_Tutorial/extApi.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/extApi.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/extApi.c$(DependSuffix): extApi.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/extApi.c$(ObjectSuffix) -MF$(IntermediateDirectory)/extApi.c$(DependSuffix) -MM "extApi.c"

$(IntermediateDirectory)/extApi.c$(PreprocessSuffix): extApi.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/extApi.c$(PreprocessSuffix) "extApi.c"

$(IntermediateDirectory)/extApiPlatform.c$(ObjectSuffix): extApiPlatform.c $(IntermediateDirectory)/extApiPlatform.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/V_rep_Tutorial/extApiPlatform.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/extApiPlatform.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/extApiPlatform.c$(DependSuffix): extApiPlatform.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/extApiPlatform.c$(ObjectSuffix) -MF$(IntermediateDirectory)/extApiPlatform.c$(DependSuffix) -MM "extApiPlatform.c"

$(IntermediateDirectory)/extApiPlatform.c$(PreprocessSuffix): extApiPlatform.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/extApiPlatform.c$(PreprocessSuffix) "extApiPlatform.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


