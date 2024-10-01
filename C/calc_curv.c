#include <stdio.h>
#include <string.h> //for strlen
#include <stdlib.h>
#include <mpi.h> //for MPI function, etc

double f(double a){
  double b;
  b=a*2;
  return b;
}

double luas(double a, double b, int trap_count, double h){
  double estimate, x;  
  int i;
  
  for(i=1; i<= trap_count-1; i++){
    x = a+ i*h;
    estimate += f(x);
  }
  estimate += estimate;
  return estimate;
}

int main() {
  int my_n_trap, my_rank, comm_sz, n_trap, h;
  double a, b, a_ku, b_ku, luas_trap, total_luas;  

   MPI_Init(NULL, NULL);
  MPI_Comm_size(MPI_COMM_WORLD, &comm_sz);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
  
  if (my_rank == 0){
    printf("Masukan a : \n");
    scanf("%lf", &a);
    printf("Masukan b : \n");
    scanf("%lf", &b);
    printf("Masukan jumlah trapesium : \n");
    scanf("%d", &n_trap);
  }
  MPI_Bcast(&a, 1, MPI_DOUBLE,0, MPI_COMM_WORLD);//cara singkat kirim terima nilai ke semua proses
  MPI_Bcast(&b, 1, MPI_DOUBLE,0, MPI_COMM_WORLD);
  MPI_Bcast(&n_trap, 1, MPI_DOUBLE,0, MPI_COMM_WORLD);
  
  h = (b - a) / n_trap;
  my_n_trap = n_trap / comm_sz;
  a_ku = a + my_rank*my_n_trap*h;
  b_ku = a_ku + my_n_trap*h;
  luas_trap = luas(a_ku, b_ku, my_n_trap, h); 

  MPI_Allreduce(&luas_trap, &total_luas, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);//cara singkat kirim (ke semua proses) terima nilai dari kalkulasi di proses 0
  
  if (my_rank==0){
    printf("\nDengan n = %d trapesium, \n",n_trap);
    printf("perhitungan luas kita terhadap fungsi y=f(x)\n");
    printf("dari a = %f sampai dengan b = %f adalah %f\n", a, b, total_luas);
  }

  MPI_Finalize();
  return 0;

}
