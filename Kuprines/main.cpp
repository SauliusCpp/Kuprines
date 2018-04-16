#include <fstream>

int heaviestBackpack = 0;
int lightBackpackCount = 0;

int main()
{
	//nuskaitomi ir nustatomi duomenys
	{
		for (char pos = 0; pos < 2; pos++)
		{
			/*
			skaitytuvas atidaromas dukart del masyvu naudojimo uzdraudimo:
			pirma karta ieskomas didziausias svoris
			antra karta - lengu kupriniu skaicius
			*/
			std::ifstream reader("data\\U1.txt");

			int backpackCount;
			reader >> backpackCount;

			for (char i = 0; i < backpackCount; i++)
			{
				int backpackWeight;
				reader >> backpackWeight;

				if (pos == 0)
				{
					if (backpackWeight > heaviestBackpack)
					{
						heaviestBackpack = backpackWeight;
					}
				}
				else if (backpackWeight + backpackWeight <= heaviestBackpack)
				{
					lightBackpackCount++;
				}
			}

			reader.close();
		}
	}
	//irasomi duomenys
	{
		std::ofstream writer("data\\U1rez.txt");
		writer << heaviestBackpack << ' ' << lightBackpackCount;
		writer.close();
	}
}