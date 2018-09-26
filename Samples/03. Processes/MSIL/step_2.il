.assembly Step_2 {}
.assembly extern mscorlib {}

.method static void main()
{
	.entrypoint
	.maxstack 10
	
	ldstr 	"Введите последовательно (на отдельных строках) координаты точки x1, y1"
	call	void [mscorlib]System.Console::WriteLine(string)
	
	call	string [mscorlib]System.Console::ReadLine()
	call	float64 [mscorlib]System.Double::Parse(string)
	
	dup
	mul

	call	string [mscorlib]System.Console::ReadLine()
	call	float64 [mscorlib]System.Double::Parse(string)

	dup
	mul
	
	add
	
	call	float64 [mscorlib]System.Math::Sqrt(float64)
	
	call	void [mscorlib]System.Console::WriteLine(float64)
		
	ret
}