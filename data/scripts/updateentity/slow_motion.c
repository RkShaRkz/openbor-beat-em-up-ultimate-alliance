void main()
{//Suicide if enemy count reach to 0
	void self 	= getlocalvar("self");
	int eCount 	= openborvariant("count_enemies");
	
	if(eCount <= 1)
	{
		damageentity(self, self, 1, 0, openborconstant("ATK_NORMAL1"));
	}
}