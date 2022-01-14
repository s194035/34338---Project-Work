
//Read temperature inside
float temp__in (){
  
  float t_in = dht_in.readTemperature();
  
  if(isnan(t_in)){
    return 0; //failed to read temperature
  }
  return t_in; //return inside temperature
}

//Read temperature outside
float temp__out (){
  
  float t_out = dht_out.readTemperature();
  
  if(isnan(t_out)){
    return 0; // failed to read temperature
  }
  return t_out; //return temperature outside
}
