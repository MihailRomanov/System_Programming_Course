.assembly Step_2 {}

.method static void main()
{
	.entrypoint
	.maxstack 3
	
	ldc.r8	3.0	
	dup
	mul

	ldc.r8	4.0
	dup
	mul
	
	add
	
	call	float64 [mscorlib]System.Math::Sqrt(float64)
	
	call	void [mscorlib]System.Console::WriteLine(float64)
	call	string [mscorlib]System.Console::ReadLine()
	
	pop
		
	ret
}