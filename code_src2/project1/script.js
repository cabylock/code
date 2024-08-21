


function register()
{
   var username = document.getElementById("username").value;
   var password = document.getElementById("password").value;

   let url = 'http://localhost:27018/register'
   fetch( url , 
      {
         method: 'POST',
         headers: {
            'Content-Type': 'application/json'
         },
         body: JSON.stringify({username: username, password: password}),

      }
   )
   .then( (data) => data.text() )
   .then( (data) => document.getElementById('result').innerHTML = data )


}

function login()
{
   

   var username = document.getElementById("username").value;
   var password = document.getElementById("password").value;

   let url = 'http://localhost:27018/login'
   
   fetch(url   , 
   {
      method: 'POST',
      headers: {
         'Content-Type': 'application/json'
      },
      body:JSON.stringify({username: username, password: password}),
   } 
   )
   .then( (data)  => data.text()) 
   .then( (data) => document.getElementById('result').innerHTML = data )



}

