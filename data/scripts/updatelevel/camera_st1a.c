void main()
{//Adjust camera with XPOS check

	if(openborvariant("xpos") >= 600){
		changelevelproperty("camerazoffset", 0);
	}
}