bool pno[num+1];
vi prime;
void SieveOfEratosthenes(int num) {
   memset(pno, true, sizeof(pno));
   for (int i = 2; i*i< = num; i++) {
      if (pno[i] == true) {
         for (int j = i*2; j< = num; j + = i)
            pno[j] = false;
      }
   }
   for (int i = 2; i< = num; i++)
      if (pno[i])
          prime.pb(i);
}
