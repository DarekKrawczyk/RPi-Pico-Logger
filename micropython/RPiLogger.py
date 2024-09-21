import uos

from uos import listdir

class Colors:
    Entering: str = "\x1b[38;2;220;220;170m"
    YELLOW: str = "\033[38;5;226m"
    DEEP_BLUE: str = "\033[38;5;21m"
    LIGHT_BLUE: str = "\033[38;5;81m"
    BLUE: str = "\033[38;5;27m"
    GREEN: str = "\033[38;5;28m"
    OLIVE_GREEN: str = "\033[38;5;154m"
    RED: str = "\033[38;5;196m"
    PURPLE: str = "\033[38;5;129m"
    ORANGE: str = "\033[38;5;208m"
    CYAN: str = "\033[38;5;51m"
    Reset: str = "\033[0m"

class VariableColorMapper:
    @staticmethod
    def VarToColor(variable: str) -> str:
        if variable == "int" or variable == "Int":
            return Colors.BLUE
        elif variable == "str" or variable == "String":
            return Colors.GREEN
        elif variable == "float" or variable == "Float":
            return Colors.BLUE
        elif variable == "list" or variable == "List":
            return Colors.GREEN
        elif variable == "tuple" or variable == "Tuple":
            return Colors.BLUE
        elif variable == "dict":
            return Colors.BLUE
        return Colors.BLUE

class MessageType:
    Message: str = f"({Colors.OLIVE_GREEN}Message{Colors.Reset}): "
    Warning: str = f"({Colors.RED}Warning{Colors.Reset}): "
    Print: str = f"({Colors.PURPLE}Print{Colors.Reset}): "
    Exception: str = f"({Colors.RED}Exception{Colors.Reset}): "

class RPiPrettyPrint:
    @staticmethod
    def PrintEnterScope(functionName: str = ""):
        print(f"{RPiLogger.WhiteSpaces()}({Colors.YELLOW}Entering{Colors.Reset}){ "" if functionName == "" else (" -> "+functionName+"()")}")
        
    @staticmethod
    def PrintLeaveScope(functionName: str = ""):
        print(f"{RPiLogger.WhiteSpaces()}({Colors.YELLOW}Leaving{Colors.Reset}){ "" if functionName == "" else (" <- "+functionName+"()")}")
        
    @staticmethod
    def PrintVariable(variable, variableName: str, variableType: str):
        if variableType == "<class 'int'>":
            #print(f"{RPiLogger.WhiteSpaces()}| {Colors.BLUE}Int{Colors.Reset} {varName} = {Colors.LIGHT_BLUE}dec({Colors.Reset}{variable}{Colors.LIGHT_BLUE}){Colors.Reset}")
            print(f"{RPiLogger.WhiteSpaces()}| {Colors.BLUE}Int{Colors.Reset} {variableName} = {variable}")
        elif variableType == "<class 'str'>":
            print(f"{RPiLogger.WhiteSpaces()}| {Colors.GREEN}String{Colors.Reset} {variableName} = {Colors.ORANGE}\"{variable}\"{Colors.Reset}")
        elif variableType == "<class 'float'>":
            print(f"{RPiLogger.WhiteSpaces()}| {Colors.BLUE}Float{Colors.Reset} {variableName} = {variable}")
        elif variableType == "<class 'list'>":
            if len(variable) > 0:
                contentAsString: str = str(variable)
                listType: str = f"{type(variable[0])}"
                clearType = listType.split("'")[1] 
                print(f"{RPiLogger.WhiteSpaces()}| {Colors.GREEN}List{Colors.Reset}<{VariableColorMapper.VarToColor(clearType)}{clearType}{Colors.Reset}> {variableName} = {contentAsString}") 
            else: 
                print(f"{RPiLogger.WhiteSpaces()}| {Colors.GREEN}List{Colors.Reset} is empty")
        elif variableType == "<class 'tuple'>":
            raise Exception("Not implemented")
        elif variableType == "<class 'dict'>":
            raise Exception("Not implemented")

    @staticmethod
    def PrintVariableDetails(variable, variableName: str, variableType: str):
        if variableType == "<class 'int'>":
            print(f"{RPiLogger.WhiteSpaces()}| ({Colors.LIGHT_BLUE}Debug{Colors.Reset}) {variableName} => {{ {Colors.LIGHT_BLUE}dec({Colors.Reset}{variable}{Colors.LIGHT_BLUE}){Colors.Reset} | {Colors.LIGHT_BLUE}bin({Colors.Reset}{bin(variable).replace("0b", "")}{Colors.LIGHT_BLUE}){Colors.Reset} | {Colors.LIGHT_BLUE}hex({Colors.Reset}{hex(variable).replace("0x", "").upper()}{Colors.LIGHT_BLUE}){Colors.Reset} }}")
        elif variableType == "<class 'str'>":
            raise Exception("Not implemented")
        elif variableType == "<class 'float'>":
            raise Exception("Not implemented")
        elif variableType == "<class 'list'>":
            raise Exception("Not implemented")
        elif variableType == "<class 'tuple'>":
            raise Exception("Not implemented")
        elif variableType == "<class 'dict'>":
            raise Exception("Not implemented")
        
    @staticmethod
    def PrintList(list: list, message: str) -> None:
        print(f"{RPiLogger.WhiteSpaces()}| ({Colors.PURPLE}PrintList{Colors.Reset}): {list}")
        
    @staticmethod
    def Print(message: str, messageType: str) -> None:
        print(f"{RPiLogger.WhiteSpaces()}| {messageType}{Colors.ORANGE}'{message}'{Colors.Reset}")
    
    @staticmethod
    def PrintWallSymbol():
        print(f"{RPiLogger.WhiteSpaces()}|")

class RPiLogger:
    # Private static counter for entries.
    __counter: int = 0
    __indentWidth: int = 2

    def __init__(self) -> None:
        pass
    
    @staticmethod
    def ScriptsInDevice() -> list:
        files: list = uos.listdir()
        scripts: list = [file for file in files if file.endswith('.py')]
        return scripts
    
    @staticmethod
    def PrintScriptsInDevice() -> None:
        scripts: list = RPiLogger.ScriptsInDevice()
        RPiPrettyPrint.PrintList(scripts, "Scripts in device")
    
    @staticmethod
    def LogVar(variable, variableName: str = "\"\"") -> None:
        varType: str = f"{type(variable)}"
        try:
            if variableName == "\"\"":
                variableName = [name for name, val in locals().items() if val is variable][0]
            RPiPrettyPrint.PrintVariable(variable, variableName, varType)
        except Exception as exception:
            RPiPrettyPrint.PrintVariable(variable, variableName, varType)
    
    @staticmethod
    def DebugVar(variable, variableName: str = "\"\"") -> None:
        varType: str = f"{type(variable)}"
        try:
            if variableName == "\"\"":
                variableName = [name for name, val in locals().items() if val is variable][0]
            RPiPrettyPrint.PrintVariableDetails(variable, variableName, varType)
        except Exception as exception:
            RPiPrettyPrint.PrintVariableDetails(variable, variableName, varType)
    
    @staticmethod
    def EnterScope(scopeName: str = "") -> None:
        RPiPrettyPrint.PrintEnterScope(scopeName)
        RPiLogger.__counter += 1
        RPiPrettyPrint.PrintWallSymbol()
    
    @staticmethod
    def LeaveScope(scopeName: str = "") -> None:
        RPiPrettyPrint.PrintWallSymbol()
        if RPiLogger.__counter > 0:
            RPiLogger.__counter -= 1
        RPiPrettyPrint.PrintLeaveScope(scopeName)

    @staticmethod
    def Print(message: str) -> None:
        RPiPrettyPrint.Print(message, MessageType.Print)
        
    @staticmethod
    def Message(message: str) -> None:
        RPiPrettyPrint.Print(message, MessageType.Message)
        
    @staticmethod
    def Warning(message: str) -> None:
        RPiPrettyPrint.Print(message, MessageType.Warning)

    @staticmethod
    def Exception(message: str) -> None:
        RPiPrettyPrint.Print(message, MessageType.Exception)

    @staticmethod
    def WhiteSpaces() -> str:
        return RPiLogger.__counter * RPiLogger.__indentWidth * " "