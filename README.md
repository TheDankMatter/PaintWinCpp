# PaintWinCpp

Wymagania dla dll i aplikacji(Ostatnia poprawna kompilacja):  
Visual Studio 2017  
Windows SDK 10.0.18362.0  
Narzędzia platformy v141  
Projekt składa się z 2 części:  
Jedna z nich to DLL zawierająca przestrzeń nazw  
Druga z nich to aplikacja, tworzona wg szablonów Paint.  
Aplikacja korzysta w WinAPI, korzysta z HDC do tworzenia obszaru rysowania.  
Rysowanie każdej figury - tworzymy obszar selekcji (jego bezwzględne wymiary), a dopiero w jego środku samą figurę, w określonym kolorze (sourceFiles/DrawObj).  
Operacja zapisu korzysta z uniwersalnego JSONa  
