void main()
{
	void self = getlocalvar("self");
	
	if(openborvariant("xpos") >= 1){
		killentity(self);
	}
}
