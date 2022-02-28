## Crack Method

1.Modify jump  
2.modify key value  
3.Analyze the code  
4.modify logical code  

### Usually

local variable: ebp - xxx  
parameter: ebp + xxx  

## Switch Multi Branch

### The Branch List

cause the "case" must be an integer, buf "if" is not


## Call

call address01 ==  
push eip
jmp xxxxxx  
......  
pop eip  
jmp eip  
  
address01: the address of function start  
ret ==  
pop eip  
jmp eip  

retn 0x8 ==  
pop eip  
add esp, 0x8  
jmp eip  

eax: usually get the return value  

## Fast Call

Extra using ecx,edx for paramater:  
push oprd1  
push oprd2  
mov ecx,oprd3  
mov edx,oprd4  
call address01  

## This Pointer

Extra using ecx for this pointer in class(always have parameter:this pointer)  
push oprd1  
push oprd2  
mov ecx,oprd3  

# Decorated Name Convention

## C

Calling Convention|Decorate Convention
--|:--:|--:
stdcall|\_funname@num
\_cdecl|\_funname
fastcall|@\_funname@num

## C++

Calling Convention|Decorate Convention
--|:--:|--:
stdcall|?funname@@YG(ParameterTable)@Z
\_cdecl|?funname@@YA(ParameterTable)@Z
fastcall|?funname@@YI(ParameterTable)@Z

# IDA

## Addressing

xxxxFFFF:  
xxxx is generated random number  

# Function

## Console Program

main(): contain 3 parameters  

## Win32 Program

winmain(): contain 4 parameters  

## Virtual Function

`VTBL(Virtual Table List)`

    Fun[2]={fun1address, fun2address}
    fun1address = the first function address
    fun2address = the second function address
    Call[Fun] = call fun1
    Call[Fun + 4] = call fun2