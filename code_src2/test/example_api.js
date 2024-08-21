const http = require('http');

const API_KEY = '833da71fcbb92708ea4a410acb3bba19'
const apiUrl = `https://api.openweathermap.org/data/2.5/weather?lat=44.34&lon=10.99&appid=${API_KEY}`;
async function apiReturn()
{ 
  const port = 27017;
  let count = 0 ; 
  const hostname = '127.0.0.1';
  let server = http.createServer(async(req, res) => {  // hàm xử lý request
    res.statusCode = 200;
    let data = await getdata();
    
    res.end(JSON.stringify(data)+"  " + count );
    count++;
  });

  server.listen(port, hostname, () => {  // hàm khởi tạo server
    console.log(`Server running at http://${hostname}:${port}/`);
  })
}
async function getdata() // hàm lấy dữ liệu từ api weaather 
{

  let response = await fetch(apiUrl);
  let data = await response.json();
  return data;
    
}
apiReturn();