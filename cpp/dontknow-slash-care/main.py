from modules.database import *
from modules.identity import *
from modules.messages import *
from modules.functions import *
import os
import discord
from discord.ext import commands
webhookName = "icebox246"
bot = commands.Bot(command_prefix='$')
token = os.getenv("DISCORD_TOKEN")
async def sendWebhookMessage(ctx,identity,message):
    if not ctx.author == bot.user:
        allWebhooks = await ctx.channel.webhooks()
        selectedWebhook = None
        for webhook in allWebhooks:
            if webhook.name == webhookName:
                selectedWebhook = webhook
        if selectedWebhook == None:
            selectedWebhook = await ctx.channel.create_webhook(name=webhookName)
        await selectedWebhook.send(message,username=identity["name"],avatar_url=identity["photo_url"])

async def alekMsg(ctx):
    await sendWebhookMessage(ctx,zawo,alek1)
    await sendWebhookMessage(ctx,zawo,alek2)

@bot.command()
async def dzierg(ctx):
    await sendWebhookMessage(ctx,dziergID,dziergText)

@bot.command()
async def dzierg2(ctx):
    await sendWebhookMessage(ctx,dziergID,dziergText2)

@bot.command()
async def horny(ctx):
    await sendWebhookMessage(ctx,icebox,adamR)

@bot.command()
async def text(ctx):
    await sendWebhookMessage(ctx,icebox,filmText)

@bot.command()
async def mouson(ctx):
    await sendWebhookMessage(ctx,mousonID,kurwinText)

@bot.event
async def on_ready():
    await bot.change_presence(activity=discord.Game(name="Roblox"))
    print("Connected to discord")

@bot.event
async def on_message(ctx):
    messageContent = ctx.content.lower()
    if messageContent.startswith('square'):
        await sendWebhookMessage(ctx,squarebot, await squareCount(messageContent))
    if messageContent.startswith('kamil'):
        await sendWebhookMessage(ctx,spike,getRandomMessage(sMessage))
    elif messageContent.startswith('adam'):
       await sendWebhookMessage(ctx,icebox,getRandomMessage(aMessage))
    elif messageContent.startswith('zawo'):
       await sendWebhookMessage(ctx,zawo,getRandomMessage(zMessage))
    elif messageContent.startswith('tocha'):
       await sendWebhookMessage(ctx,tocha,getRandomMessage(tMessage))
    elif messageContent.startswith('borno'):
       if "powiedz" in messageContent:
            await sendWebhookMessage(ctx,borno,replaceAllBorno(messageContent))
       else:
            await sendWebhookMessage(ctx,borno,getRandomMessage(bMessage))
    elif messageContent.startswith('alek'):
        await alekMsg(ctx)
    await bot.process_commands(ctx)


bot.run(token)
