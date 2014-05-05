
__kernel void parameterized_kernel ( __global int* arg1 )
{
	arg1[0] = $param$;
}

