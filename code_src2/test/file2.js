

const API_KEY = '833da71fcbb92708ea4a410acb3bba19'
const apiUrl = `https://api.openweathermap.org/data/2.5/weather?lat=44.34&lon=10.99&appid=${API_KEY}`;

  async function getdata()
{

  let response = await fetch(apiUrl)
  let data = await response.json();
  console.log(data);
    
}

module.exports= 
{
  abc: getdata()
}








