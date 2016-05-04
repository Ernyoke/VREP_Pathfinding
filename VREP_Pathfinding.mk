##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=VREP_Pathfinding
ConfigurationName      :=Debug
WorkspacePath          :=/home/ervin/CProjects/codelite_workspace/codelite_workspace
ProjectPath            :=/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ervin
Date                   :=04/05/16
CodeLitePath           :=/home/ervin/.codelite
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
ObjectsFileList        :="VREP_Pathfinding.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
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
CXXFLAGS :=  -g -O0 -std=c++14 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Playground.cpp$(ObjectSuffix) $(IntermediateDirectory)/PathInterface.cpp$(ObjectSuffix) $(IntermediateDirectory)/A_StarPath.cpp$(ObjectSuffix) $(IntermediateDirectory)/Position.cpp$(ObjectSuffix) $(IntermediateDirectory)/OutOfBoundException.cpp$(ObjectSuffix) $(IntermediateDirectory)/HistoricalPosition.cpp$(ObjectSuffix) $(IntermediateDirectory)/NoPathException.cpp$(ObjectSuffix) $(IntermediateDirectory)/VRepApi.cpp$(ObjectSuffix) $(IntermediateDirectory)/ConnectionErrorException.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/remoteApi_extApi.c$(ObjectSuffix) $(IntermediateDirectory)/remoteApi_extApiPlatform.c$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Playground.cpp$(ObjectSuffix): Playground.cpp $(IntermediateDirectory)/Playground.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/Playground.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Playground.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Playground.cpp$(DependSuffix): Playground.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Playground.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Playground.cpp$(DependSuffix) -MM "Playground.cpp"

$(IntermediateDirectory)/Playground.cpp$(PreprocessSuffix): Playground.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Playground.cpp$(PreprocessSuffix) "Playground.cpp"

$(IntermediateDirectory)/PathInterface.cpp$(ObjectSuffix): PathInterface.cpp $(IntermediateDirectory)/PathInterface.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/PathInterface.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PathInterface.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PathInterface.cpp$(DependSuffix): PathInterface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PathInterface.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PathInterface.cpp$(DependSuffix) -MM "PathInterface.cpp"

$(IntermediateDirectory)/PathInterface.cpp$(PreprocessSuffix): PathInterface.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PathInterface.cpp$(PreprocessSuffix) "PathInterface.cpp"

$(IntermediateDirectory)/A_StarPath.cpp$(ObjectSuffix): A_StarPath.cpp $(IntermediateDirectory)/A_StarPath.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/A_StarPath.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/A_StarPath.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/A_StarPath.cpp$(DependSuffix): A_StarPath.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/A_StarPath.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/A_StarPath.cpp$(DependSuffix) -MM "A_StarPath.cpp"

$(IntermediateDirectory)/A_StarPath.cpp$(PreprocessSuffix): A_StarPath.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/A_StarPath.cpp$(PreprocessSuffix) "A_StarPath.cpp"

$(IntermediateDirectory)/Position.cpp$(ObjectSuffix): Position.cpp $(IntermediateDirectory)/Position.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/Position.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Position.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Position.cpp$(DependSuffix): Position.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Position.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Position.cpp$(DependSuffix) -MM "Position.cpp"

$(IntermediateDirectory)/Position.cpp$(PreprocessSuffix): Position.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Position.cpp$(PreprocessSuffix) "Position.cpp"

$(IntermediateDirectory)/OutOfBoundException.cpp$(ObjectSuffix): OutOfBoundException.cpp $(IntermediateDirectory)/OutOfBoundException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/OutOfBoundException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/OutOfBoundException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OutOfBoundException.cpp$(DependSuffix): OutOfBoundException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OutOfBoundException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/OutOfBoundException.cpp$(DependSuffix) -MM "OutOfBoundException.cpp"

$(IntermediateDirectory)/OutOfBoundException.cpp$(PreprocessSuffix): OutOfBoundException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OutOfBoundException.cpp$(PreprocessSuffix) "OutOfBoundException.cpp"

$(IntermediateDirectory)/HistoricalPosition.cpp$(ObjectSuffix): HistoricalPosition.cpp $(IntermediateDirectory)/HistoricalPosition.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/HistoricalPosition.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/HistoricalPosition.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/HistoricalPosition.cpp$(DependSuffix): HistoricalPosition.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/HistoricalPosition.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/HistoricalPosition.cpp$(DependSuffix) -MM "HistoricalPosition.cpp"

$(IntermediateDirectory)/HistoricalPosition.cpp$(PreprocessSuffix): HistoricalPosition.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/HistoricalPosition.cpp$(PreprocessSuffix) "HistoricalPosition.cpp"

$(IntermediateDirectory)/NoPathException.cpp$(ObjectSuffix): NoPathException.cpp $(IntermediateDirectory)/NoPathException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/NoPathException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NoPathException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NoPathException.cpp$(DependSuffix): NoPathException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/NoPathException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/NoPathException.cpp$(DependSuffix) -MM "NoPathException.cpp"

$(IntermediateDirectory)/NoPathException.cpp$(PreprocessSuffix): NoPathException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NoPathException.cpp$(PreprocessSuffix) "NoPathException.cpp"

$(IntermediateDirectory)/VRepApi.cpp$(ObjectSuffix): VRepApi.cpp $(IntermediateDirectory)/VRepApi.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/VRepApi.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/VRepApi.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/VRepApi.cpp$(DependSuffix): VRepApi.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/VRepApi.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/VRepApi.cpp$(DependSuffix) -MM "VRepApi.cpp"

$(IntermediateDirectory)/VRepApi.cpp$(PreprocessSuffix): VRepApi.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/VRepApi.cpp$(PreprocessSuffix) "VRepApi.cpp"

$(IntermediateDirectory)/ConnectionErrorException.cpp$(ObjectSuffix): ConnectionErrorException.cpp $(IntermediateDirectory)/ConnectionErrorException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/ConnectionErrorException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ConnectionErrorException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ConnectionErrorException.cpp$(DependSuffix): ConnectionErrorException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ConnectionErrorException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ConnectionErrorException.cpp$(DependSuffix) -MM "ConnectionErrorException.cpp"

$(IntermediateDirectory)/ConnectionErrorException.cpp$(PreprocessSuffix): ConnectionErrorException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ConnectionErrorException.cpp$(PreprocessSuffix) "ConnectionErrorException.cpp"

$(IntermediateDirectory)/remoteApi_extApi.c$(ObjectSuffix): remoteApi/extApi.c $(IntermediateDirectory)/remoteApi_extApi.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/remoteApi/extApi.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/remoteApi_extApi.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/remoteApi_extApi.c$(DependSuffix): remoteApi/extApi.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/remoteApi_extApi.c$(ObjectSuffix) -MF$(IntermediateDirectory)/remoteApi_extApi.c$(DependSuffix) -MM "remoteApi/extApi.c"

$(IntermediateDirectory)/remoteApi_extApi.c$(PreprocessSuffix): remoteApi/extApi.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/remoteApi_extApi.c$(PreprocessSuffix) "remoteApi/extApi.c"

$(IntermediateDirectory)/remoteApi_extApiPlatform.c$(ObjectSuffix): remoteApi/extApiPlatform.c $(IntermediateDirectory)/remoteApi_extApiPlatform.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/GIT/VREP_Pathfinding/remoteApi/extApiPlatform.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/remoteApi_extApiPlatform.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/remoteApi_extApiPlatform.c$(DependSuffix): remoteApi/extApiPlatform.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/remoteApi_extApiPlatform.c$(ObjectSuffix) -MF$(IntermediateDirectory)/remoteApi_extApiPlatform.c$(DependSuffix) -MM "remoteApi/extApiPlatform.c"

$(IntermediateDirectory)/remoteApi_extApiPlatform.c$(PreprocessSuffix): remoteApi/extApiPlatform.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/remoteApi_extApiPlatform.c$(PreprocessSuffix) "remoteApi/extApiPlatform.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


