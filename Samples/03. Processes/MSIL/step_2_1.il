.assembly Step_2_1 {}
.assembly extern mscorlib {}

.method static void main()
{
	.entrypoint
	.maxstack 5
	
	//ldstr "В введенной строке {0} символ(а,ов)"
	
	//call string [mscorlib]System.Console::ReadLine()
	//call instance int32 [mscorlib]System.String::get_Length()
	ldc.i4 5
	box [mscorlib]System.Int32
	callvirt instance string [mscorlib]System.Object::ToString()
			
	call void [mscorlib]System.Console::WriteLine(string)
		
	ret
}