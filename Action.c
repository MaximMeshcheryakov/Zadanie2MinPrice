Action()
{

	/* Itinerary */
	
	web_reg_save_param_ex(
    "ParamName=TicketPrice", 
    "LB/IC=Total Charge: $ ",
    "RB/IC= <BR",
    "Ordinal=all",
	LAST);
	
			
	web_reg_save_param_ex(
    "ParamName=FlightID", 
    "LB/IC=name=\"flightID\" value=\"",
    "RB/IC=\"  ",
    "Ordinal=all",
	LAST);
	
		
	web_reg_save_param_ex(
    	"ParamName=NumberOfTickets", 
    	"LB/IC=<b>A total of ", 	
    	"RB/IC= scheduled flight",								
    	"Ordinal=1",
	LAST);
	

	web_url("Itinerary Button", 
		"URL={Host}/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/nav.pl?page=menu&in=flights", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);
	

	lr_output_message("Total Number of tickets=%d",atoi(lr_eval_string("{NumberOfTickets}")));
	lr_output_message("Price ticket 1=%d",atoi(lr_eval_string("{TicketPrice_1}")));
	lr_output_message("Price ticket 2=%d",atoi(lr_eval_string("{TicketPrice_2}")));
	lr_output_message("Price ticket 3=%d",atoi(lr_eval_string("{TicketPrice_3}")));
	
	if((atoi(lr_eval_string("{TicketPrice_1}"))<atoi(lr_eval_string("{TicketPrice_2}"))) && (atoi(lr_eval_string("{TicketPrice_1}"))<atoi(lr_eval_string("{TicketPrice_3}")))) {
		min = atoi(lr_eval_string("{TicketPrice_1}"));
		lr_save_string("1","num");
		//numstr = num.ToString();
	}
	if((atoi(lr_eval_string("{TicketPrice_2}"))<atoi(lr_eval_string("{TicketPrice_1}"))) && (atoi(lr_eval_string("{TicketPrice_2}"))<atoi(lr_eval_string("{TicketPrice_3}")))) {
		min = atoi(lr_eval_string("{TicketPrice_2}"));
		lr_save_string("2","num");
		//numstr = num.ToString();
	}
	if((atoi(lr_eval_string("{TicketPrice_3}"))<atoi(lr_eval_string("{TicketPrice_2}"))) && (atoi(lr_eval_string("{TicketPrice_3}"))<atoi(lr_eval_string("{TicketPrice_1}")))) {
		min = atoi(lr_eval_string("{TicketPrice_3}"));
		lr_save_string("3","num");
		//numstr = num.ToString();
	}
	
	lr_output_message("Num Min Price ticket=%d",atoi(lr_eval_string("{num}")));
	lr_output_message("Min Price ticket=%d",min);
	
	/* DEL TICKET */

	web_submit_data("itinerary.pl", 
		"Action={Host}/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer={Host}/cgi-bin/itinerary.pl", 
		"Snapshot=t12.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value={FlightID_1}", ENDITEM, 
		"Name=flightID", "Value={FlightID_2}", ENDITEM, 
		"Name=flightID", "Value={FlightID_3}", ENDITEM, 
		"Name={num}", "Value=on", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=removeFlights.x", "Value=69", ENDITEM, 
		"Name=removeFlights.y", "Value=8", ENDITEM, 
		LAST);
	
	return 0;
}