.assembly Step_3 {}

.method void main()
{
	.entrypoint
	.maxstack 10
	.locals init (string str, int32 startWord, int32 endWord)
	
	ldstr	"Введите строку из нескольких слов, разделенных пробелом"
	call	void [mscorlib]System.Console::WriteLine(string) 
	
	call	string [mscorlib]System.Console::ReadLine()
	stloc	str
	
	ldloc	str
	ldstr	" "
	call	instance int32 [mscorlib]System.String::IndexOf(string)
	ldc.i4	1
	add
	stloc	startWord
	
	ldloc	str
	ldstr	" "
	ldloc	startWord
	call	instance int32 [mscorlib]System.String::IndexOf(string, int32)
	stloc	endWord
	
	ldloc	str
	ldloc	startWord
	ldloc	endWord
	ldloc	startWord
	sub
	call	instance string	[mscorlib]System.String::Substring(int32, int32)
	
	call	void [mscorlib]System.Console::WriteLine(string)
	
	ret
}