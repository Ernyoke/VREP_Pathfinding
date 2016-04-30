##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=A_star_V_rep
ConfigurationName      :=Debug
WorkspacePath          := "/home/ervin/CProjects/codelite_workspace"
ProjectPath            := "/home/ervin/CProjects/codelite_workspace/A_star_V_rep"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=ervin
Date                   :=30/04/16
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
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="A_star_V_rep.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
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
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Playground.cpp$(ObjectSuffix) $(IntermediateDirectory)/PathInterface.cpp$(ObjectSuffix) $(IntermediateDirectory)/A_StarPath.cpp$(ObjectSuffix) $(IntermediateDirectory)/Position.cpp$(ObjectSuffix) $(IntermediateDirectory)/OutOfBoundException.cpp$(ObjectSuffix) $(IntermediateDirectory)/HistoricalPosition.cpp$(ObjectSuffix) $(IntermediateDirectory)/NoPathException.cpp$(ObjectSuffix) 



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
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/A_star_V_rep/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Playground.cpp$(ObjectSuffix): Playground.cpp $(IntermediateDirectory)/Playground.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/A_star_V_rep/Playground.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Playground.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Playground.cpp$(DependSuffix): Playground.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Playground.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Playground.cpp$(DependSuffix) -MM "Playground.cpp"

$(IntermediateDirectory)/Playground.cpp$(PreprocessSuffix): Playground.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Playground.cpp$(PreprocessSuffix) "Playground.cpp"

$(IntermediateDirectory)/PathInterface.cpp$(ObjectSuffix): PathInterface.cpp $(IntermediateDirectory)/PathInterface.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/A_star_V_rep/PathInterface.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PathInterface.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PathInterface.cpp$(DependSuffix): PathInterface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PathInterface.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PathInterface.cpp$(DependSuffix) -MM "PathInterface.cpp"

$(IntermediateDirectory)/PathInterface.cpp$(PreprocessSuffix): PathInterface.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PathInterface.cpp$(PreprocessSuffix) "PathInterface.cpp"

$(IntermediateDirectory)/A_StarPath.cpp$(ObjectSuffix): A_StarPath.cpp $(IntermediateDirectory)/A_StarPath.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/A_star_V_rep/A_StarPath.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/A_StarPath.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/A_StarPath.cpp$(DependSuffix): A_StarPath.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/A_StarPath.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/A_StarPath.cpp$(DependSuffix) -MM "A_StarPath.cpp"

$(IntermediateDirectory)/A_StarPath.cpp$(PreprocessSuffix): A_StarPath.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/A_StarPath.cpp$(PreprocessSuffix) "A_StarPath.cpp"

$(IntermediateDirectory)/Position.cpp$(ObjectSuffix): Position.cpp $(IntermediateDirectory)/Position.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/A_star_V_rep/Position.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Position.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Position.cpp$(DependSuffix): Position.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Position.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Position.cpp$(DependSuffix) -MM "Position.cpp"

$(IntermediateDirectory)/Position.cpp$(PreprocessSuffix): Position.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Position.cpp$(PreprocessSuffix) "Position.cpp"

$(IntermediateDirectory)/OutOfBoundException.cpp$(ObjectSuffix): OutOfBoundException.cpp $(IntermediateDirectory)/OutOfBoundException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/A_star_V_rep/OutOfBoundException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/OutOfBoundException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/OutOfBoundException.cpp$(DependSuffix): OutOfBoundException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/OutOfBoundException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/OutOfBoundException.cpp$(DependSuffix) -MM "OutOfBoundException.cpp"

$(IntermediateDirectory)/OutOfBoundException.cpp$(PreprocessSuffix): OutOfBoundException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/OutOfBoundException.cpp$(PreprocessSuffix) "OutOfBoundException.cpp"

$(IntermediateDirectory)/HistoricalPosition.cpp$(ObjectSuffix): HistoricalPosition.cpp $(IntermediateDirectory)/HistoricalPosition.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/A_star_V_rep/HistoricalPosition.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/HistoricalPosition.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/HistoricalPosition.cpp$(DependSuffix): HistoricalPosition.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/HistoricalPosition.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/HistoricalPosition.cpp$(DependSuffix) -MM "HistoricalPosition.cpp"

$(IntermediateDirectory)/HistoricalPosition.cpp$(PreprocessSuffix): HistoricalPosition.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/HistoricalPosition.cpp$(PreprocessSuffix) "HistoricalPosition.cpp"

$(IntermediateDirectory)/NoPathException.cpp$(ObjectSuffix): NoPathException.cpp $(IntermediateDirectory)/NoPathException.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/ervin/CProjects/codelite_workspace/A_star_V_rep/NoPathException.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/NoPathException.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/NoPathException.cpp$(DependSuffix): NoPathException.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/NoPathException.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/NoPathException.cpp$(DependSuffix) -MM "NoPathException.cpp"

$(IntermediateDirectory)/NoPathException.cpp$(PreprocessSuffix): NoPathException.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/NoPathException.cpp$(PreprocessSuffix) "NoPathException.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


