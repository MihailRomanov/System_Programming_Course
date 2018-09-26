.assembly Step_4 {}

.method void main()
{
	.entrypoint
	.locals (string str)
	
input_loop:
	ldstr	"Введите целое число (для завершения работы - пустую строку)"
	call	void [mscorlib]System.Console::WriteLine(string)
	
	call	string [mscorlib]System.Console::ReadLine()
	stloc	str
	
	ldloc	str
	call	bool [mscorlib]System.String::IsNullOrEmpty(string)
	brtrue	exit

	ldloc	str
	call	int32 [mscorlib]System.Int32::Parse(string)
	
	ldc.i4	2
	rem
	ldc.i4	0
	ceq
	
	brfalse	odd
	
	ldstr 	"Число - четное\n"
	br	print

odd:
	ldstr	"Число - нечетное\n"
	
print:
	call	void [mscorlib]System.Console::WriteLine(string)

	br	input_loop
	
exit:

	ret
}