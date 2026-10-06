namespace Hafta1.Soru_1;
class Program
{
    static void Main()
    {
      Console.WriteLine("10 adet sayı girişi yapınız.");
      List<int> numbers = new List<int>();
      for(int i=0; i<10; i++)
      {
        Console.Write("Lütfen bir sayı giriniz: ");
        if (int.TryParse(Console.ReadLine(), out int number))
        {
            numbers.Add(number);
        }
        else
        {
            Console.WriteLine("Geçersiz giriş. Lütfen bir sayı giriniz.");
            i--; // Geçersiz giriş durumunda döngüyü tekrar ettir
        }
      }
      Console.Write("Girdiğiniz sayılar: ");
      Console.WriteLine(string.Join(", ",numbers));
    }
}