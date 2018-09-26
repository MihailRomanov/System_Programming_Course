.assembly Step_1 {}
.assembly extern mscorlib {}
//.assembly extern System.Windows.Forms as forms {}

.method static void main()
{
	.entrypoint
	.maxstack 1
	
	ldstr "Привет, мир!"
	call void [mscorlib]System.Console::WriteLine(string)
	
	call string [mscorlib]System.Console::ReadLine()
	pop
	
	ret
}