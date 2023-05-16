#pragma once

class Application
{
public:
	// Application instance'i istemiyoruz, o nedenle default constructor tanimini kaldirabiliriz.
	Application() = delete;

	// Program ilk basladiginda izlenen prosedurleri icerir.
	// 
	// - isletim sisteminden bellek isteme
	// - cesitli sistemleri hazirlama
	static bool Initialize();

	// Programimizi kapatirken izlenen prosedurleri icerir.
	//
	// - isletim sistemine kullanilan bellegi iade etme
	// - cesitli sistemleri kapatma
	static int Exit();

	// Program bellegi hazirlandiktan sonra motorun kullanacagi built-in
	// kaynaklari yuklemek icin izlenen prosedurleri icerir.
	// 
	// - built-in shader compilation
	// - built-in texture loading
	// - built-in asset loading
	static void Load();

	// Motorun kullandigi built-in ve diger kaynaklari isletim sistemine
	// iade etmek icin izlenen prosedurleri icerir.
	// 
	// - texture, shader, asset belleklerini isletim sistemine iade etme
	static void Unload();


	// Bir frame'i cizmek icin gereken tum mantik ve aritmetik islemlerini icerir.
	// 
	// - kullanicidan gelen input'u isleme
	// - simulasyon dunyasini guncelleme (update/tick)
	// - cizim icin gerekli datayi toplama
	// - cizim icin komutlari grafik islemcisine gonderme
	// - uygulama penceresine son resmi aktarma
	static void UpdateAndRender();

private:
	// Uygulama veri ve state tanimlari
};