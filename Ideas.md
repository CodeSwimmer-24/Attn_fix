> This will be a worker application that will connect worker with clients/customers.

Our focus is on two parties
- The workers: The low class domestic workers
- The customers: The people looking for workers

This will be two way communication channel
- The clients can create opening in the platform, and mention criterions for the type of worker they want
- The workers can create their profile into the system.
- The clients can search through the profiles of workers
- We will display two lists
	- job opening list
	- worker profile list

We will take these steps [[Steps|Steps]]

## 15 Jan 2024
There are two models:
- simple and easy model
	- It is not a role based access platform, no need of signin / signup
	- The profile of the worker must be created by admin side
	- customer needs to signin / signup
	- will get categories of workers to search through
		- like home maid, cook, car driver, shop keeper, helper etc.
	- In each category one can see various profiles, and one can inquire, call or message us. (Inquire means further hiring process Q&A)
		- This requires consent of both parties, the worker and the customer, we will act as the middle men for it.
	- Pros:
		1. Easy to make, launch in the market.
		2. layman workers can be easily targeted
	- Cons:
		1. We have to handle all the registration and inquiries
- advanced model:
	- Both customers and the workers will sign in and sign up.
	- Customers will create job openings.
	- workers will apply for them
	- customers can same way scroll through workers profile as well
	- (Note: The workers from model 1 will also be shown here)
	- The customers and workers will handle the inquiries themselves.
	- Pros:
		1. Advanced and more sophisticated information
		2. More features
	- Cons:
		1. Will take more time to develop
		2. The workers need to be decently educated

So the plan is to develop model 1 quickly, launch it, then introduce model 2.

**But first We need to have some [[Research]].**

