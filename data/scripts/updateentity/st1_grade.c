void main()
{
	void self = getlocalvar("self");
	
	if(openborvariant("xpos") >= 600){
		killentity(self);
	}
}
