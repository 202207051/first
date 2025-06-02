package oop;

public class Tv01
{
	public static class Tv
	{
		String model;
		String color;
		int size;
		boolean power;
		int channel;
		int volume;

		void power()
		{
			power = true;
		}

		void channelUp()
		{
			++channel;
		}

		void channelDown()
		{
			--channel;
		}

		void volumeUp()
		{
			++volume;
		}

		void volumeDown()
		{
			--volume;
		}

		public static void main(String[] args)
		{

			Tv t = new Tv();

			t.model = "Ultra";
			t.size = 64;
			t.color = "black";
			t.channel = 9;
			t.volume = 10;

			System.out.println(t.model + t.color);
			System.out.println(t.channel);
			System.out.println(t.size);
			System.out.println(t.volume);
		}
	}
}
