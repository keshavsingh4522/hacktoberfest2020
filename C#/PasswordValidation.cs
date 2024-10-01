using System;
 
namespace passwords
{

  private bool validatePassword(string pass) //Function that validates if a password is strong enough
  {
      bool upper = false, lower = false, digit = false, simbol = false, len = false;
      if (pass.Length >= 8) len = true;
      for (int i = 0; i < pass.Length; i++)
      {
          if (Char.IsUpper(pass, i)) upper = true;
          else if (Char.IsLower(pass, i)) lower = true;
          else if (Char.IsDigit(pass, i)) digit = true;
          else simbol = true;
      }
      if (upper == true && lower == true && digit == true && len == true && simbol = true)
          return true;
      else
          return false;
  }
}
