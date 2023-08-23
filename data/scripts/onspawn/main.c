void nBmap()
{//Change subject_to_wall to 0 in st7b and st8b at top floor
	void self 	= getlocalvar("self");
	int nBmap	= openborvariant("numbasemaps");
	
	if(nBmap >= 1)	
	{
		changeentityproperty(self, "subject_to_wall", 0);
	}
}