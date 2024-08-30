
function log( value, checked)  {     
      let li = document.createElement('li');
      let ul = document.createElement('ul');

      let  checkbox = document.createElement('input');
      checkbox.type = 'checkbox';
      checkbox.id="checkbox";

      let span = document.createElement('span');
      

      let delete_button = document.createElement('button');
      delete_button.textContent = 'Delete';
      delete_button.className = 'delete';

      span.textContent = value;
      checkbox.checked = checked;
      if(checked)
      {
            li.style.textDecoration = 'line-through';
      }

      span.onclick = function() // update data
      {
            span.contentEditable = true;
            span.focus();
            span.onblur = function()
            {
            fetch("http://localhost:27018/edit",
                  {
                        method: 'POST',
                        body: JSON.stringify({value: value, new_value: span.textContent}),
                  }
                  )
            
            value = span.textContent;
            }
      }

      checkbox.onclick = function() // update checkbox
      {
            fetch("http://localhost:27018/edit",
            {
                  method: 'POST',
                  body: JSON.stringify({ value : value, checked : checkbox.checked, new_value : value}),
            }
            )
            li.style.textDecoration = checkbox.checked ? 'line-through' : 'none';
            checked = checkbox.checked;
      }
      delete_button.onclick = function() //delete
      {
            fetch("http://localhost:27018/delete",
                  {
                        method: 'POST',
                        body: JSON.stringify({value:value}),
                  }
            )
            li.remove();
      }
      li.appendChild(checkbox);
      li.appendChild(span);
      li.appendChild(delete_button);
      document.getElementById('list').appendChild(li);
}

function api_add(value,checked)
{
      fetch("http://localhost:27018/add",
            {
                  method: 'POST',
                  body: JSON.stringify({value : value, checked : checked}),
            }
      )
      log(value,checked);
   
     
}

function addTodo()
{     let value = document.getElementById('input').value;
      let checked = false;
      if( value )
      {   api_add(value,checked);
            }
      document.getElementById('input').value = '';
}
function press_enter(event)
{
      if(event.keyCode == 13)
      {
            addTodo();
      }
}


window.onload = function()
{
      fetch("http://localhost:27018/get")
      .then( (response) => response.json() )
      .then( (data) => 
      {
            data.forEach( (element) => 
            {
                  log(element.value, element.checked);
            } 
            )
      } 
      )
}




