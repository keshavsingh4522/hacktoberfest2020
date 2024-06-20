// Be Cool
// A Unity 2d Player Movement Script By TheCoolDev


using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    public float speed;
    public float jumpForce;
    private float moveInput;

    private Rigidbody2D rb;

    private bool facingRight = true;

    private bool isGrounded;
    public Transform groundCheck;
    public float checkRadius;
    public LayerMask whatIsGround;

    private int extraJumps;
    public int extraJumpsValue;

    // Start is called before the first frame update
    void Start()
    {
        extraJumps = extraJumpsValue;
        rb = GetComponent<Rigidbody2D>();
    }

    // Update is called once per frame
    void FixedUpdate()
    {
        isGrounded = Physics2D.OverlapCircle(groundCheck.position, checkRadius, whatIsGround);


        moveInput = Input.GetAxis("Horizontal");

        rb.velocity = new Vector2(moveInput * speed, rb.velocity.y);


        if(facingRight == false && moveInput > 0){
        	Flip();
        } else if(facingRight == true && moveInput < 0){
        	Flip();
        }
    }


    void Update(){
    	
    	if(isGrounded == true){
    		extraJumps = 2;
    	}

    	if(Input.GetKeyDown(KeyCode.UpArrow) && extraJumps > 0){
    		rb.velocity = Vector2.up * jumpForce;
    		extraJumps--;
    	} else if(Input.GetKeyDown(KeyCode.UpArrow) && extraJumps == 0 && isGrounded == true){
    		rb.velocity = Vector2.up * jumpForce;
    	}


    }


    void Flip()
    {
    	facingRight = !facingRight;
    	
    	transform.Rotate(0f, 180f, 0f);
    }
}
