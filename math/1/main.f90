program lab1_10

   integer, parameter      :: M = 11, N = 11
   integer                 :: nofun = 0, k = 0, i = 0
   real                    :: lowerbound = 0, upperbound = 0, h = 0, abserr = 0, relerr = 0, res = 0, errest = 0, flag = 0
   real                    :: x_k(N), B(N), C(N), D(N), xNodes(M), fNodes(M)
   real                    :: result(N), spline_result(N)
   
   data xNodes /0.000, 0.300, 0.600, 0.900, 1.200, 1.500, 1.800, 2.100, 2.400, 2.700, 3.000/
   data fNodes /0.000, 0.259, 0.451, 0.593, 0.699, 0.777, 0.835, 0.878, 0.909, 0.933, 0.950/
  
  lowerbound = 0
  upperbound = 3
   
   abserr = 0.000001
   relerr = 0.000001
   x_k = [(0.3 * k, k = 0, 10)]
   

   call SPLINE(M, xNodes, fNodes, B, C, D)
   
   do i = 1, N
      result(i) = calcLagrange(M, xNodes, fNodes, x_k(i))
      spline_result(i) = SEVAL(N, x_k(i), xNodes, fNodes, B, C, D)
   end do
   
   write (*, "('absError = ', f11.6, '; relError = ', f11.6)") abserr, relerr
   write (*, *)
   do k = 1, N
      write(*, "('Polynomial at = ', f22.10, '; Result = ', f22.10)") x_k, result
      write(*, "('Spline Polynomial at = ', f15.10, '; Spline Result = ', f15.10)") x_k, spline_result
      write (*, *)
   end do
      
   call QUANC8(f, lowerbound, upperbound, abserr, relerr, res, errest, nofun, flag) 
   write (*, *)
   write(*, "('f(1-exp(-x)) = ', f11.9, '; Errest = ', f11.9, '; Nofun = ', i4, '; Flag = ', f15.9)") res, errest, nofun, flag
       

contains
    include 'QUANC8.FOR'
    include 'SPLINE.FOR'
    include 'SEVAL.FOR'    
    
    real pure function f(x)
       real, intent(in)  :: x
       f = 1 - exp(-x)
    end function f 
    
    real function calcLagrange(nodesAmount, xNodes, fNodes, x_ki) result(value)
      integer, intent(in)  ::nodesAmount    
      real, intent(in)  :: xNodes(nodesAmount), fNodes(nodesAmount), x_ki
      integer             :: i, j
      real                :: term
      
      value = 0
      do i = 1, nodesAmount
          term = 1
          do j = 1, nodesAmount
            if (i /= j) then
                term = term * (x_ki - xNodes(j)) / (xNodes(i) - xNodes(j))
            end if
         end do
         value = value + fNodes(i) * term
      end do
    end function calcLagrange  
    
end program lab1_10
