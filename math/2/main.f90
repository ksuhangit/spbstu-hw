program lab_2 
   implicit none

   character(*), parameter    :: input_file = 'input.txt'
   integer                    :: In = 0 , Out = 0 , N = 0 , i = 0 , M = 8
   real                       :: temp = 0 , cond = 0 , delta = 0 , x1_norm = 0, x2_norm = 0, cond_1 = 0, cond_2 = 0
   integer, dimension(8)      :: ipvt
   real, allocatable          :: A(:,:)
   real, dimension(8)         :: B, B_new, x_1, x_2, work, G
   real, dimension(5)         :: P
   real, dimension(8,8)       :: A_new, ATR, F


   data P /1.0, 0.1, 0.01, 0.0001, 0.000001/
   data B /54, -72, -33, -15, 180, -5, -14, -131/
   
   open(file = input_file, newunit = In)
      read(In,*) N
      allocate(A(N,N))
      read(In,*)(A(:,i), i = 1, N)
   close(In)

   write(Out,*) "      P(i)     |      cond_1     |     cond_2      |           delta "
 
   do i = 1, 5, 1
      A_new = A
      B_new = B
      temp = P(i)
      A_new(1, 1) = temp - 3
      B_new(1) = 2 * temp + 54
      x_1 = B_new

      ATR = Transpose(A_new)
   F = MATMUL(ATR, A_new)
   G = MATMUL(ATR, B_new)
   x_2 = G


   call DECOMP(M, M, A_new, cond, ipvt, work)
   cond_1 = cond 
   call SOLVE(M, M, A_new, x_1, ipvt)

   call DECOMP(M, M, F, cond, ipvt, work)
   cond_2 = cond
   call SOLVE(M, M, F, x_2, ipvt)

   x1_norm = get_norma(x_1)
   x2_norm = get_norma(x_2)

   delta = (x1_norm - x2_norm)/x1_norm
      write(*, "(f15.13, ' | ', f15.5,' | ', f15.5, ' | ', f15.13)" ) P(i), cond_1, cond_2, delta
  end do
contains  
   include 'DECOMP.FOR'
   include 'SOLVE.FOR'


   pure real function get_norma(x) result(norma_result)
      real, intent(in)      :: x(8)
      real                  :: norma
      integer               :: i
   
      norma = 0
   
      do i = 1, 8, 1
         norma = norma + x(i) ** 2
      end do
   
      norma_result = sqrt(norma)
   end function get_norma
end program lab_2
